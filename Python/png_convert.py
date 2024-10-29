from pathlib import Path
from PIL import Image
import sys


VALID_IMAGES = (
    ".jpg",
    ".jpeg",
    ".webp",
    ".png"
)


def convert_file(file: Path) -> None:
    if (
        file.exists() is False or
        file.suffix not in VALID_IMAGES
    ):
        return
    img = Image.open(file)
    img = img.convert("RGBA")
    img.save(file.with_suffix(".png"))
    print(f"[IMAGE {file} CONVERTED]")


def convert_dir(dir: Path) -> None:
    dir_list = [dir]
    while (dir_list):
        root = dir_list.pop()
        for i in root.iterdir():
            if (i.is_file()):
                convert_file(i)
            elif (i.is_dir()):
                dir_list.append(i)


def main() -> None:
    src = Path(sys.argv[1])
    
    if (src.exists() is False):
        print(f"{src} is not a valid source")
        exit()

    if (src.is_file()):
        convert_file(src)
    elif (src.is_dir()):
        convert_dir(src)
    


if __name__ == "__main__":
    main()