from pathlib import Path
import random
import sys


def main() -> None:
    d = sys.argv[1]
    d = Path(d)
    
    for file in d.iterdir():
        file.rename(file.with_stem(f"tmp_{random.randint(0, 666)}_{file.stem}"))
    
    for i, file in enumerate(d.iterdir()):
        file: Path
        file.rename(file.with_stem(str(i)))


if __name__ == "__main__":
    main()