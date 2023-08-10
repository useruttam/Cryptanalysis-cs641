import re
_File = open("output_pairs.txt", "w")
_P = re.compile("Slowly, a new text starts appearing on the screen. It reads ...")
_Flag = False
for _Frags in open("allout.log"):
    if _Flag:
        _File.write("{}\n".format(_Frags.strip()))
        _Flag = False
    else:
        for _Element in re.finditer(_P, _Frags):
            if _Element:
                _Flag = True
_File.close()

