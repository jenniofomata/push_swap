*This activity has been created as part of the 42 curriculum by jenofoma, \<login2\>*

# push_swap

## Description

`push_swap` sorts a list of integers using only two stacks and a restricted
instruction set, and prints the shortest sequence of instructions it can find.

There are two stacks. Stack `a` starts holding every integer given on the
command line, with the first argument on top; stack `b` starts empty. The goal
is to leave `a` sorted in ascending order, smallest on top, and `b` empty. The
only moves allowed are:

| Instruction | Effect |
|---|---|
| `sa` / `sb` / `ss` | swap the top two elements of `a` / of `b` / of both |
| `pa` / `pb` | move the top of `b` onto `a` / the top of `a` onto `b` |
| `ra` / `rb` / `rr` | rotate up: first element becomes last, on `a` / `b` / both |
| `rra` / `rrb` / `rrr` | rotate down: last element becomes first, on `a` / `b` / both |

The program does not execute the sort interactively — it analyses the input,
generates the instruction sequence, and writes it to standard output, one
instruction per line. Feeding that output to a checker confirms the sequence
really does sort the stack.

What makes this version of the project more than a sorting exercise is that the
binary embeds **four different strategies** and must be able to choose between
them at runtime. The cost of an algorithm here is **not** measured in CPU time
but in the **number of push_swap instructions it emits**, which is the figure
every complexity claim in this document refers to.

## Instructions

### Build

```
make
```

The top-level Makefile first builds `libft/libft.a` by invoking libft's own
Makefile, then compiles `push_swap` with `cc -Wall -Wextra -Werror` and links
against it. Project object files go into `obj/`; libft's stay beside its
sources. `clean`, `fclean` and `re` are forwarded to libft as well. Nothing
relinks when no source has changed, and editing a libft source correctly
triggers a rebuild of the archive and a relink of the binary.

### Run

```
./push_swap [strategy] [--bench] <integers>
```

The integers may be given as separate arguments or as a single quoted,
space-separated string — `./push_swap 3 2 1` and `./push_swap "3 2 1"` are
equivalent.

| Flag | Strategy selected |
|---|---|
| `--simple` | selection sort, O(n²) |
| `--medium` | chunk sort, O(n√n) |
| `--complex` | LSD binary radix sort, O(n log n) |
| `--adaptive` | chooses a method from the measured disorder — **this is the default** |
| `--bench` | additionally print metrics to standard error |

Running with no arguments prints nothing and exits successfully.

### Errors

On invalid input the program writes `Error` followed by a newline to **standard
error** and exits with status 1. Input is rejected when an argument is not an
integer, when a value does not fit in an `int`, when a value appears twice, or
when an argument is empty or contains only whitespace.

### Benchmark mode

`--bench` writes metrics to standard error only, leaving standard output free
for the instruction stream, so the two can be separated in a pipeline:

```
./push_swap --bench --adaptive 4 67 3 87 23 2> bench.txt | ./checker_linux 4 67 3 87 23
```

```
[bench] disorder: 40.00%
[bench] strategy: Adaptive (small) / O(1)
[bench] total_ops: 9
[bench] sa: 0 sb: 0 ss: 0 pa: 2 pb: 2
[bench] ra: 4 rb: 0 rr: 0 rra: 1 rrb: 0 rrr: 0
```

The `strategy` line reports the strategy that was *requested*, then — for an
`--adaptive` run only — the method it dispatched to in parentheses, then the
complexity class of that method. This is why an `Adaptive` run can report a
class other than the one its own name suggests: the five values above are sorted
by the `n ≤ 5` branch, so the class shown is that branch's `O(1)`.

### Helper scripts

Two scripts under `tools/` are provided for development. They are not part of
the graded submission.

```
tools/test_errors.sh      # error-handling matrix
tools/bench.sh [runs]     # operation counts for every strategy
```

Both expect the evaluation checker at `../push-swap-eval/checker_linux`; set the
`CHECKER` environment variable to point somewhere else.

## The disorder metric

Every complexity decision the adaptive strategy makes is driven by a single
number. **Disorder** is the proportion of pairs of elements that are in the
wrong relative order:

```
disorder = (number of pairs i < j where a[i] > a[j]) / (n * (n - 1) / 2)
```

It is 0 for an already sorted stack and 1 for a stack in exactly reverse order,
and it is computed **before any instruction is generated**.

Two implementation notes. The input is normalised to ranks `0 .. n-1` before
anything else happens, which lets every algorithm work on small dense integers
instead of the original values; because ranking preserves the relative order of
every pair, it leaves the disorder unchanged. And the count is accumulated in a
`long`, since for the maximum useful input sizes the pair count comfortably
exceeds what an `int` holds.

## Algorithms

### `--simple` — selection sort, O(n²)

Repeatedly find the smallest element remaining in `a`, rotate it to the top
using whichever of `ra` or `rra` is closer, and `pb` it. Once `a` is empty, `b`
holds the values in descending order from the top, so `n` × `pa` returns them to
`a` in ascending order.

**Bound.** Bringing the minimum to the top of a stack of size *m* costs at most
⌊m/2⌋ rotations, because the cheaper of the two directions is always taken.
Summing as the stack shrinks, plus one `pb` and one `pa` per element:

```
Σ(m = 1..n) ⌊m/2⌋  +  2n   ≤   n²/4 + 2n   =   O(n²)
```

This is the baseline. It is the only strategy whose cost is essentially
independent of how disordered the input is, which is exactly what makes it a
useful point of comparison for the other three.

### `--medium` — chunk sort, O(n√n)

The rank range is cut into chunks of size `c = 2⌊√n⌋`, giving `k = ⌈n/c⌉`
chunks, and `k` is therefore Θ(√n).

*Phase 1* walks the chunks in ascending order. For the chunk currently being
collected, `a` is rotated to the nearest element belonging to it — nearest
measured from the top *or* the bottom, taking whichever is cheaper — and that
element is pushed to `b`. If the pushed value falls in the **lower half** of its
chunk, one `rb` sends it to the bottom of `b`.

That `rb` is the detail the whole algorithm turns on. It leaves `b` in a
"folded" arrangement: reading from the top, the upper halves of the chunks in
descending order; reading from the bottom upwards, the lower halves, also in
descending order. So the next value needed is always near one end of `b` or the
other, never buried in the middle.

*Phase 2* repeatedly brings the maximum of `b` to the top with whichever of `rb`
or `rrb` is closer, and `pa`s it.

**Bound.** Phase 1 needs at most one traversal of `a` per chunk, so at most
`k · n = O(n√n)` rotations, plus *n* pushes. In phase 2 the folded layout keeps
every target within O(c) of one end of `b`, giving at most `n · c = O(n√n)`
rotations and *n* pops. Both phases are O(n√n), so the strategy is.

Choosing `c = Θ(√n)` is not arbitrary: phase 1 costs roughly `n²/2c` and phase 2
roughly `n·c/α`, and the sum is minimised when `c` is proportional to √n, which
is the same √n that gives the required complexity class. The constant factor 2
in `c = 2⌊√n⌋` was selected by measurement — see *Performance* below.

### `--complex` — LSD binary radix sort, O(n log n)

Because the values were normalised to ranks `0 .. n-1`, every value fits in
`B = ⌈log₂ n⌉` bits, and a least-significant-digit radix sort over those bits
sorts the stack in `B` passes.

Each pass examines every element of `a` exactly once: if the current bit is 0 the
element is pushed to `b`, otherwise it is rotated with `ra`. After the pass,
everything in `b` is returned with `pa`. Because the zero-bit group is pushed
first and returned on top, each pass is a stable partition on that bit, which is
what makes LSD radix correct. The loop stops early if the stack is already
sorted.

**Bound.** A pass over *m* elements costs *m* instructions for the partition plus
at most *m* for the returns, so at most 2*m*. With `B = ⌈log₂ n⌉` passes:

```
total ≤ 2n⌈log₂ n⌉ = O(n log n)
```

In practice roughly half the elements are pushed on any given pass, so the
measured cost is closer to `1.5·n·⌈log₂ n⌉`.

This is the strategy chosen for the most disordered inputs, and it was picked
over a quicksort or merge sort adaptation for one specific reason: its bound is
a worst-case guarantee that falls directly out of the structure of the algorithm
— the number of passes is fixed in advance and no pass can exceed 2n — rather
than an average-case or pivot-dependent argument.

### `--adaptive` — disorder-driven selection (default)

The adaptive strategy measures disorder first and then dispatches:

| Condition | Method | Class |
|---|---|---|
| `n ≤ 5` | hand-tuned small sorts | O(1) |
| `disorder < 0.2` | LIS + cost-based reinsertion | O(n²) |
| `0.2 ≤ disorder < 0.5` | chunk sort | O(n√n) |
| `disorder ≥ 0.5` | radix sort | O(n log n) |

**Why the `n ≤ 5` case comes first.** The complexity targets the subject sets per
regime are *upper bounds*, and at a fixed size of five or fewer every method is
trivially within all of them, so short-circuiting is permitted. It is also
necessary: a stack such as `2 1 0` has a disorder of 1.00 and would be routed to
the radix sort, which needs about nine instructions where two are enough. For
three elements the order is identified directly and resolved in at most two
instructions; for four or five, the smallest elements are pushed to `b`, the
remaining three are sorted, and they are pushed back — at most ten instructions
for any permutation of five.

**Why LIS below 0.2.** Selection sort would satisfy the O(n²) requirement, but
its cost barely moves when the input is nearly ordered, which wastes the one
situation where the measurement tells us something useful. Instead the longest
increasing subsequence of `a` is computed with an O(n²) dynamic program. Its
members are already in the correct relative order, so they stay; one full
rotation of `a` — exactly *n* instructions — pushes every element that is *not*
in the subsequence onto `b`, leaving `a` holding a sorted sequence that is merely
rotated.

Each element of `b` is then reinserted by cost. For every candidate, the cost of
rotating `b` to bring it to the top is added to the cost of rotating `a` to bring
its insertion point to the top; when both rotations run in the same direction
they are merged into `rr` or `rrr` and counted once. The cheapest candidate is
executed and pushed. A final rotation puts the smallest element on top.

The worst case is O(n²): each of the `k = n − |LIS|` reinsertions costs O(n)
rotations, and `k` can be as large as *n*. But `k` shrinks as the input gets
closer to sorted, and the cost falls with it, which is precisely the behaviour
the low-disorder regime should have. Measured on 500 elements, this method uses
under 1000 instructions on an almost-ordered stack where the chunk sort needs
close to 1800.

**Why chunk sort and radix sort above it.** Once disorder passes 0.2 the
increasing subsequence is no longer long enough to be worth preserving, and the
chunk sort's cost — which depends on *n* rather than on how ordered the input is
— becomes the better deal. Above 0.5 the input is effectively random, the
O(n√n) term overtakes `n log n` at these sizes, and the radix sort's fixed pass
count wins. The two cut-off values themselves are fixed by the subject.

## Performance

Operation counts, averaged over repeated runs on random input, produced with
`tools/bench.sh`:

| Input | `--simple` | `--medium` | `--complex` | default |
|---|---|---|---|---|
| 100 numbers | ~1460 | ~650 | ~1084 | ~650–1084 |
| 500 numbers | — | ~5950 | ~6784 | ~5950–6784 |

Thresholds for reference: 100 numbers — under 2000 to pass, 1500 good, 700
excellent. 500 numbers — under 12000 to pass, 8000 good, 5500 excellent.

The default strategy spans a range at both sizes because a random permutation
has an expected disorder of almost exactly 0.5, so it falls on either side of
the top cut-off from one run to the next and is dispatched accordingly.

## Project layout

```
Makefile             builds libft, then push_swap
push_swap.h          types, constants and prototypes
libft/               libft sources, header and Makefile

main.c               entry point
parse.c              flag parsing and argument collection
parse_num.c          integer parsing with range checking
validate.c           duplicate detection, rank normalisation, allocation
error.c              error reporting and cleanup
stack.c              stack mechanics
emit.c               instruction output and counting
ops.c                sa sb ss pa pb
ops_rot.c            ra rb rr
ops_rrot.c           rra rrb rrr
move.c               shared rotation and selection helpers
sort.c               strategy dispatch
sort_small.c         optimal sorts for n <= 5
sort_simple.c        selection sort
sort_medium.c        chunk sort
sort_complex.c       radix sort
sort_lis.c           longest increasing subsequence extraction
insert.c             cost-based reinsertion
insert_rot.c         rotation application, including rr/rrr merging
sort_adaptive.c      disorder-driven method selection
disorder.c           disorder metric
bench.c              benchmark output
bench_fmt.c          benchmark formatting helpers
utils.c              argument-scanning helpers

tools/               development scripts, not part of the submission
```

Every instruction emitted by the program passes through a single function,
`emit()` in `emit.c`, which writes the instruction and updates the per-type
counters. Nothing else writes to standard output.

## Use of libft

The project reuses the libft written earlier in the curriculum. Its sources and
its own Makefile are copied into `libft/` and the archive is built from there,
as the subject requires; the library is not duplicated or modified.

| Function | Used for |
|---|---|
| `ft_memmove` | shifting stack contents for push, rotate and reverse rotate |
| `ft_calloc` | allocating both stacks and the rank, LIS and bookkeeping arrays |
| `ft_strncmp`, `ft_strlen` | exact matching of the strategy and benchmark flags |
| `ft_isdigit` | digit scanning in the integer parser |
| `ft_putstr_fd`, `ft_putnbr_fd` | writing instructions, `Error`, and benchmark output |

Only four small helpers are defined in the project itself, because libft has no
equivalent: `is_sep` and `is_flag` for argument scanning, `ft_abs` for rotation
costs, and `emit` for instruction output. The integer parser is deliberately not
built on `ft_atoi`, which cannot report overflow — detecting values outside the
`int` range is a required error case, so `parse_num.c` does the conversion
itself and rejects anything that does not fit.

## Resources

- *The Art of Computer Programming, Volume 3: Sorting and Searching*, Donald
  Knuth — selection, radix and insertion sorts, and the inversion count used as
  the disorder metric.
- *Introduction to Algorithms*, Cormen, Leiserson, Rivest and Stein — chapter 8
  on radix sort and the correctness argument for stable LSD passes.
- Longest increasing subsequence — the standard O(n²) dynamic program, used for
  the low-disorder strategy.
- `man 2 write`, `man 3 malloc` — the permitted external functions.
- The 42 Norm, version 3 — formatting rules this codebase and `libft/` follow.
- libft, written earlier in the curriculum — reused here as described above.

### Use of AI

> **To be written before submission.** The subject requires this section to state
> which tasks AI was used for and which parts of the project it touched. Points
> to cover:
>
> - which tasks (design discussion, parsing, a specific algorithm, the benchmark
>   harness, this README, conformance checking against the subject, none of them)
> - which files or sections each of those touched
> - what was verified afterwards, and how
>
> Anything listed here must be something both learners can explain at the
> defence.

## Contributions

| Area | jenofoma | \<login2\> |
|---|---|---|
| Parsing, validation, error handling | | |
| Stack representation and instructions | | |
| Simple strategy | | |
| Medium strategy | | |
| Complex strategy | | |
| Adaptive strategy and disorder metric | | |
| Benchmark mode | | |
| Testing and tuning | | |
| Documentation | | |

*To be completed: both learners must be listed as contributors in the
repository, and this table must record who worked on what.*
