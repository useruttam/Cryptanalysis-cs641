from utils import *
__Textp = open("inputs.txt", "r")
__Textc = open("outputs.txt", "r")
Powers_ = [[] for x in range(8)]
var_tot_ = [[[] for x in range (8)] for vary in range(8)]
__prmpts = []
__prmptsout = []
for x in range(8):
    __prmpts.append(__Textp.readline().split())
    __prmptsout.append(__Textc.readline().split())
    __comi = [16*(ord(__prmpts[x][vary][2*x]) - ord('f')) + (ord(__prmpts[x][vary][2*x+1]) - ord('f')) for vary in range(128)]
    outs = [16*(ord(__prmptsout[x][vary][2*x]) - ord('f')) + (ord(__prmptsout[x][vary][2*x+1]) - ord('f')) for vary in range(128)]
    for vary in range(1, 127):
        for k in range(1, 128):
            f = 1
            for varx, y in zip(__comi, outs):
                if y != Raise(Multiply(Raise(Multiply(Raise(varx, vary), k), vary), k), vary):
                    f = 0
                    break 
            if f:
                Powers_[x].append(vary)
                var_tot_[x][x].append(k)
__Textp.close()
__Textc.close()
for x in range(7):
    __comi = [16*(ord(__prmpts[x][vary][2*x]) - ord('f')) + (ord(__prmpts[x][vary][2*x+1]) - ord('f')) for vary in range(128)]
    outs = [16*(ord(__prmptsout[x][vary][2*(x+1)]) - ord('f')) + (ord(__prmptsout[x][vary][2*(x+1)+1]) - ord('f')) for vary in range(128)]
    for vary in range(1, 128):
        for one_pow, one_main in zip(Powers_[x+1], var_tot_[x+1][x+1]):
            for two_pow, two_main in zip(Powers_[x], var_tot_[x][x]):
                f = 1
                for varx, y in zip(__comi, outs):
                    if y != Raise(SUM(Multiply(Raise(Multiply(Raise(varx, two_pow), two_main), two_pow), vary), Multiply(Raise(Multiply(Raise(varx, two_pow), vary), one_pow), one_main)), one_pow):
                        f = 0
                        break
                if f:
                    Powers_[x+1] = [one_pow]
                    Powers_[x] = [two_pow]
                    var_tot_[x+1][x+1] = [one_main]
                    var_tot_[x][x] = [two_main]
                    var_tot_[x+1][x] = [vary]

print(var_tot_)
print(Powers_)
