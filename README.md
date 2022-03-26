# Element Reduction 🌊 🗿 🔥 💨

The solution to a puzzle a friend gave me, written in C (unfortunately, it was one of the rules).

## How to Build

On a PowerShell run the following command:

```
.\make.ps1
```

## How to Run

On a PowerShell run the following command:
```
.\run.ps1 <input-length>
```

The argument `<input-length>` is an integer representing the length of the sequence that should be given to the program.

## The Puzzle

We have a sequence of cards, represented as a string of characters.
Each card has an element, represented by the corresponding character:

- Water, represented by `W`;
- Earth, represented by `E`;
- Fire, represented by `F`;
- Air, represented by `A`;

The idea is to reduce the sequence of pairs, by eliminating pairs of cards with elements that cancel out -- Water and Fire cancel each other out, as well as Earth and Air.
The sequence is only fully reduced once it contains no pair of adjacent cards that cancel each other out.

## The Input

The program receives as input a string through the `stdin`. This string starts with a number which is the length of the card sequence, followed by a sequence of characters of the given length that represents the sequence.
Examples are:

- `2FW`
- `10AEWWWFAWEF`
- `0`

## The Output

The program outputs a sequence of characters, corresponding to the fully reduced sequence of cards.

## How it Works

The program relies on two structures -- the `Cards` and the `CardsPairIter`.

`Cards` represents a sequence of cards, represented by a pointer to the beginning of the sequence and its length.
This structure is light, being made up of only two `int`-sized elements, making it safe to pass around by value.

`CardsPairIter` is a wrapper around a `Cards` structure with two pointers, pointing at two adjacent cards.
This structure is also quite light, containing only four `int`-sized elements, making it also safe to pass around by value.

The brunt of the program relies on two functions which operate on a `CardsPairIter` -- `tryReducePair()` and `next()`.
The `tryReducePair()` function takes a `CardsPairIter` and if the cards it is pointing out cancel each other out, it takes them out of the sequence replacing them by `0`.
Here `0` represents a card that was removed from the sequence -- this allows us to avoid having to resize the array when we remove a card.

The `next()` function takes a pointer to a `CardsPairIter` and modifies it so that it points at the next pair of cards, returning `false/0` if it reached the end of the sequence.
The function ignores `0` cards, meaning that even if the sequence contains removed cards, the iterator will point at a pair of cards that are adjacent and hasn't been removed.

With these two functions, reducing a sequence is trivial -- just call `next()` and `tryReducePair()` until we reach the end of the sequence and repeat the process until we do a full pass without reducing anything.

## Requirements

- GCC

## License Information

I, Pedro Quintas, the author of this program, hereby grant you permission to do whatever the heck you want with it. However, I shall not be accountable for your actions, and reserve my right to also change this however I want in the future.
