# rigProjectComponent

Project envelope PODs: `CProject` (document metadata singleton), `CPage`
(page record, `rig.layout.page`), and `FaceInsets` (margin / bleed / slug
wire helpers). DATA ONLY.

Document read/write (`.rig`, Contract import, `.rigz`), the `CPage` codec,
and the deferred `ProjectLoadSave` Update system live in **rigProject**.
Load this pack before `rigProject` so the envelope types are registered
when documents arrive.

## Style

Format first-party `src/` and `examples/` with clang-format before commit (never `third_party/`).

```bash
./tools/format.sh
./tools/install-hooks.sh    # once per clone - pre-commit formats staged C/C++
```

Hooks only look for `clang-format` on PATH and warn, without formatting, when it is missing. Put it on PATH:

- **Windows:** install [LLVM](https://github.com/llvm/llvm-project/releases) (enable "Add LLVM to the system PATH"), or `winget install LLVM.LLVM`, then open a new shell. Confirm: `clang-format --version`.
- **macOS:** `brew install clang-format`
- **Linux:** `sudo apt install clang-format`

From a RigKit host checkout, `./tools/install-hooks.sh` wires every pack repo. Full policy: [RigKit packs Style](https://github.com/rigkid/RigKit/blob/main/packs/README.md#style).
