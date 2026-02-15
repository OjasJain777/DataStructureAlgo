def bin_to_int(s):
    d = 0
    c = s.split(".")
    for i in range(0,len(c[0])):
        d += ((2**i)*int((c[0][::-1])[i]))
    return d
def int_to_bin(g):
    st = []
    l = g
    h = ""
    while l >1:
        st.append(l%2)
        l = l//2
    st.append(l)
    for k in range(0,len(st)):
        h += str(st.pop())
    return h
class Solution(object):
    def addBinary(self, a, b):
        m = bin_to_int(a)
        n = bin_to_int(b)
        return (int_to_bin(m+n))