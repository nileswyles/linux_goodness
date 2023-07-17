#!/usr/bin/python3

import argparse
from pathlib import Path
import os

parser = argparse.ArgumentParser("Extern C-er", description="This tool wraps the detected files with C++ extern C")
parser.add_argument("path_to_file_or_directory")
parser.add_argument("-c", "--commit", dest="commit", default=False, action=argparse.BooleanOptionalAction, help="When commit is present, the script commits it's changes. Otherwise it's a dry run.")

args = parser.parse_args()

print(args)

p = Path(args.path_to_file_or_directory)

extern_c_start = "#if defined __cplusplus" + os.linesep +"extern \"C\"" + os.linesep + "{" + os.linesep + "#endif" + os.linesep
extern_c_end = "#if defined __cplusplus" + os.linesep + "}" + os.linesep + "#endif" + os.linesep

def insert_extern_c(fp):
    tmp_fp = fp.with_name(fp.name + "_tmp")
    with open(fp, mode="rb+") as f:
        tmp_f = open(tmp_fp, mode="wb")
        tmp_f.write(bytes(extern_c_start, "utf-8"))
        tmp_f.write(f.read())
        tmp_f.write(bytes(extern_c_end, "utf-8"))
        tmp_f.close()
        if args.commit:
            tmp_f = open(tmp_fp, mode="rb+")
            f.seek(0)
            f.write(tmp_f.read())
            tmp_fp.unlink(missing_ok=True)
            tmp_f.close()

def process_file(fp, tab_count):
    if fp.suffix == ".h" or fp.suffix == ".c":
        # tabs = "".join(['\t' for _ in range(tab_count)])
        # print(tabs, end="")
        print(fp)
        insert_extern_c(fp)



def recurse_dirs(p, tab_count):
    for sub_p in p.iterdir():
        if sub_p.is_dir():
            # tabs = "".join(['\t' for _ in range(tab_count)])
            # print(tabs, end="")
            # print(sub_p)
            recurse_dirs(sub_p, tab_count=tab_count+1)
        else:
            process_file(sub_p, tab_count=tab_count)

recurse_dirs(p, 0)
