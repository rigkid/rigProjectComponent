# rigProjectComponent

Project envelope PODs: `CProject` (document metadata singleton), `CPage`
(page record, `rig.layout.page`), and `FaceInsets` (margin / bleed / slug
wire helpers). DATA ONLY.

Document read/write (`.rig`, Contract import, `.rigz`), the `CPage` codec,
and the deferred `ProjectLoadSave` Update system live in **rigProject**.
Load this pack before `rigProject` so the envelope types are registered
when documents arrive.
