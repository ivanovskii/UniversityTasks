num1 = [] 
num2 = []
f1 = open("input.txt","r")
f2 = open("output.txt", "w")
string1 = f1.readline() 
string2 = f1.readline()
if len(string1) < len(string2): #Поменять местами строки, если первое число короче
    time = string1
    string1 = string2
    string2 = time
counter = 0
for i in range (len(string1) - 1): #Добавить в список цифры числа num1 в обратном порядке
    num1.append(int(string1[len(string1) - 2 - counter]))
    counter += 1
counter = 0
for i in range (len(string2) - 1): #Аналогично со вторым числом
    num2.append(int(string2[len(string2) - 2 - counter]))
    counter += 1
for i in range(len(num2)): #Запускаем цикл суммирования
    num1[i] = num1[i] + num2[i]
    if num1[i] > 9:
        num1[i + 1] = num1[i + 1] + 1
        num1[i] = num1[i] - 10
for i in range(len(num1)): 
    f2.write(str(num1[len(num1) - 1 - i]))
f2.close()
f1.close()
