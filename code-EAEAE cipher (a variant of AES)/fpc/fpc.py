from utils import *
powers = [22, 113, 38, 73, 92, 42, 19, 26]
mat = [[84, 0, 0, 0, 0, 0, 0, 0], [112, 70, 0, 0, 0, 0, 0, 0], [19, 30, 43, 0, 0, 0, 0, 0], [98, 16, 2, 12, 0, 0, 0, 0], [110, 62, 12, 104, 112, 0, 0, 0], [25, 51, 29, 51, 99, 11, 0, 0], [2, 123, 9, 103, 29, 88, 27, 0], [0, 2, 74, 22, 10, 66, 31, 38]]
my_cip = "gskfgnjiiujogfhhjnjumjmrinjqgklk"
cipher1 = my_cip[:16]
cipher2 = my_cip[16:]
one_res = make_lst(my_cip)
two_res = make_lst(cipher2)
ptr = [0 for _ in range(8)]
arrn = [0 for _ in range(8)]
for vari in range(8):
    for varj in range(1,128):
        ptr[vari] = varj
        x = EAEAE(mat, powers, ptr)
        if x[vari] == one_res[vari]:
            ptr[vari] = varj
            break
        else:
            ptr[vari] = 0
for vari in range(8):
    for varj in range(1,128):
        arrn[vari] = varj
        x = EAEAE(mat, powers, arrn)
        if x[vari] == two_res[vari]:
            arrn[vari] = varj
            break
        else:
            arrn[vari] = 0
print(to_ascii(ptr) + to_ascii(arrn))
