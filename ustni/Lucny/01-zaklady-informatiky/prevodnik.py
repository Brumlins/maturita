def binarni_do_desitkove(binarni):
    vysledek = 0
    for i, cislice in enumerate(reversed(binarni)):
        vysledek += int(cislice) * (2 ** i)
    return vysledek

def desitkova_do_binarni(dec):
    if (dec == 0):
        return "0"
    binarni = ""
    while dec > 0:
        binarni = str(dec%2) + binarni
        dec //= 2
    return binarni

print(binarni_do_desitkove("1010"))
print(desitkova_do_binarni(10))