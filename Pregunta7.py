

num1 = int(input("Inserte el primer numero: "))
num2 = int(input("Inserte el segundo numero: "))

print("Que operacion desea realizar?")
ch = input("Ingrese cualquiera de los siguientes simbolos +,-,*,/: ")

result = 0
if ch == '+':
    result = num1 + num2
elif ch == '-':
    result = num1 - num2
elif ch == '*':
    result = num1 * num2
elif ch == '/':
    result = num1 / num2
else:
    print("No se pudo reconocer!")

print(num1, ch , num2, ":", result)