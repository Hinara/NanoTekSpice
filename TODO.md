# TODO ([NanoTekspice](https://intra.epitech.eu/module/2017/B-CPP-400/PAR-4-1/acti-278570/project/file/B-CPP-400_nanotekspice.pdf))

## Components

| Component | Description | Table | internalCompute | Automated Tests | Unit Tests |
|-----------|-------------|:-----:|:---------------:|:---------------:|:----------:|
| [2716](https://intra.epitech.eu/module/2017/B-CPP-400/PAR-4-1/acti-278570/project/file/tonsil/2716.pdf) | UV Erasable PROM | ✔ | ❌ | ❌ | ❌ |
| [4001](https://intra.epitech.eu/module/2017/B-CPP-400/PAR-4-1/acti-278570/project/file/tonsil/4001.pdf) | Quad 2 input NOR Gate | ✔ | ✔ | ✔ | ✔ |
| [4008](https://intra.epitech.eu/module/2017/B-CPP-400/PAR-4-1/acti-278570/project/file/tonsil/4008.pdf) | 4-Bit full adder | ✔ | ✔ | ✔ | ✔ |
| [4011](https://intra.epitech.eu/module/2017/B-CPP-400/PAR-4-1/acti-278570/project/file/tonsil/4011.pdf) | Quad 2 input NAND Gate | ✔ | ✔ | ✔ | ✔ |
| [4013](https://intra.epitech.eu/module/2017/B-CPP-400/PAR-4-1/acti-278570/project/file/tonsil/4013.pdf) | Dual D-Type Flip-Flop | ✔ | ✔ | ❌ | ❌ |
| [4017](https://intra.epitech.eu/module/2017/B-CPP-400/PAR-4-1/acti-278570/project/file/tonsil/4017.pdf) | Johnson decade counter with 10 decoded outputs | ✔ | ✔ | ✔ | ✔ |
| [4030](https://intra.epitech.eu/module/2017/B-CPP-400/PAR-4-1/acti-278570/project/file/tonsil/4030.pdf) | Quad 2 input XOR Gate | ✔ | ✔ | ✔ | ✔ |
| [4040](https://intra.epitech.eu/module/2017/B-CPP-400/PAR-4-1/acti-278570/project/file/tonsil/4040.pdf) | 12-bit Binary counter | ✔ | ✔ | ✔ | ✔ |
| [4069](https://intra.epitech.eu/module/2017/B-CPP-400/PAR-4-1/acti-278570/project/file/tonsil/4069.pdf) | Inverted Circuit | ✔ | ✔ | ✔ | ✔ |
| [4071](https://intra.epitech.eu/module/2017/B-CPP-400/PAR-4-1/acti-278570/project/file/tonsil/4071.pdf) | Quad 2 input OR Gate | ✔ | ✔ | ✔ | ✔ |
| [4081](https://intra.epitech.eu/module/2017/B-CPP-400/PAR-4-1/acti-278570/project/file/tonsil/4081.pdf) | Quad 2 input AND Gate | ✔ | ✔ | ✔ | ✔ |
| [4094](https://intra.epitech.eu/module/2017/B-CPP-400/PAR-4-1/acti-278570/project/file/tonsil/4094.pdf) | 8-Bit Shift Register/Latch with 3-STATE Output | ✔ | ✔ | ✔ | ✔ |
| [4514](https://intra.epitech.eu/module/2017/B-CPP-400/PAR-4-1/acti-278570/project/file/tonsil/4514.pdf) | 4-Bit Latched/4-to-16 Line decoder | ✔ | ✔ | ❌ | ❌ |
| [4801](https://intra.epitech.eu/module/2017/B-CPP-400/PAR-4-1/acti-278570/project/file/tonsil/mk4801.pdf) | 1K x 8bit static RAM | ✔ | ✔ | ❌ | ❌ |

## Follow-Up

| State | Description |
|:-----:|-------------|
| ✔ | Use default for constructor and destructor when function is empty |
| ✔ | Use for range instead of for_each |
| ✔ | Use static with const attribute that depends upon the component type only |
| ✔ | Reduce number of Error classes |
| WIP | Make unit test |

## Mouli

### A - Single components - 17 tests

| Test n° | Description | Result |
|:-------:|-------------|:------:|
| 00 | DIRECT CONNECTION | ✔ |
| 01 | CLOCK | ✔ |
| 02 | TRUE | ✔ |
| 03 | FALSE | ✔ |
| 04 | AND GATE (4081) | ✔ |
| 05 | OR GATE (4071) | ✔ |
| 06 | NAND GATE (4011) | ✔ |
| 07 | NOR GATE (4001) | ✔ |
| 08 | XOR GATE (4030) | ✔ |
| 09 | NOT GATE (4069) | ✔ |
| 10 | DECODER (4514) | ❌ |
| 11 | ADDER (4008) | ✔ |
| 12 | COUNTER (4040) | ✔ |
| 13 | JOHNSON (4017) | ✔ |
| 14 | SHIFT (4094) | ✔ |
| 15 | D LATCH (4013) | ❌ |
| 16 | TERMINAL (4013) | ❌ |

### B - Combinatory logic - 7 tests

| Test n° | Description | Result |
|:-------:|-------------|:------:|
| 01 | 5 INPUT AND GATE | ✔ |
| 02 | 5 INPUT NAND GATE | ✔ |
| 03 | 5 INPUT OR GATE | ✔ |
| 04 | 5 INPUT NOR GATE | ✔ |
| 05 | MANDION | ✔ |
| 06 | ALTERED COUNTER | ✔ |
| 07 | ROM DUMP | ❌ |

### C - Sequential logic - 2 tests

| Test n° | Description | Result |
|:-------:|-------------|:------:|
| 01 | ONE BIT RAM | ✔ |
| 02 | XORED DATA ROM DUMPER | ❌ |
