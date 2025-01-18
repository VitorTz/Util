#!/usr/bin/python3
from pathlib import Path
from PIL import Image
from multiprocessing.pool import ThreadPool
import sys
import os


def _conver_to_png(path: Path) -> None:
    print(f"[CONVERTING {path}]")
    Image.open(path).convert("RGBA").save(path.with_suffix(".png"))
    os.remove(str(path))

def convert(src: Path) -> None:
    files: list[Path] = []
    q: list[Path] = [src]
    while q:
        path = q.pop(0)
        if path.is_file() and path.suffix in (".jpg", ".jpeg", ".webp"):
            files.append(path)
        elif path.is_dir():
            [q.append(p) for p in path.iterdir()]
    
    with ThreadPool(4) as pool:
        pool.map(_conver_to_png, files)
    pool.join()

def main() -> None:
    src = Path(sys.argv[1])
    if src.exists() is False:
        print(f"Invalid input! {src}")
    convert(src)


if __name__ == "__main__":
    main()