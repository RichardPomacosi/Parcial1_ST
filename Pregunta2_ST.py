print("**********ENCRIPTACIÓN CESAR***********")
nombre=input("Introduce tu nombre: ")
nombre=nombre
encriptado=""
for i in nombre:
    a=ord(i)+3
    if (a>=65 and a<=90)or(a>=97 and a<=122)or (a>=164 and a<=165):
        encriptado+=chr(a)
    elif a>90 or a>122:
        a=a-26
        encriptado+=chr(a)
    elif (a-3)==32:
        encriptado+=chr(32)
print("Su nombre encriptado es:  ")
print("\t",encriptado)

    