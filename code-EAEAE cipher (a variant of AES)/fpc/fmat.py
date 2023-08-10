from utils import *

__powers = [22, 113, 38, 73, 92, 42, 19, 26]
mat = [[84, 0, 0, 0, 0, 0, 0, 0],[112, 70, 0, 0, 0, 0, 0, 0],[0, 30, 43, 0, 0, 0, 0, 0],[0, 0, 2, 12, 0, 0, 0, 0],[0, 0, 0, 104, 112, 0, 0, 0],[0, 0, 0, 0, 99, 11, 0, 0],[0, 0, 0, 0, 0, 88, 27, 0],[0, 0, 0, 0, 0, 0, 31, 38]]

textp_ = open("inputs.txt", "r")
textc_ = open("outputs.txt", "r")

__cmd = []
__cmdout = []

for _ in range(8):
    __cmd.append(textp_.readline().split())
    __cmdout.append(textc_.readline().split())

textp_.close()
textc_.close()

for set_f in range(2,8):
    for varc in range(8-set_f):
        i = varc + set_f
        ins = [16*(ord(__cmd[varc][j][2*varc]) - ord('f')) + (ord(__cmd[varc][j][2*varc+1]) - ord('f')) for j in range(128)]
        outs = [16*(ord(__cmdout[varc][j][2*(i)]) - ord('f')) + (ord(__cmdout[varc][j][2*(i)+1]) - ord('f')) for j in range(128)]
        for k in range(1,128):
            mat[i][varc] = k
            f = 1
            for index, (x, y) in enumerate(zip(ins, outs)):
                init_arr = [0,0,0,0,0,0,0,0]
                init_arr[varc] = x
                cipher = EAEAE(mat,__powers,init_arr)
                if y != cipher[i]:
                    f = 0
                    mat[i][varc] = 0
                    break 
            if f:
                mat[i][varc] = k
                break

print(mat)
print(__powers)