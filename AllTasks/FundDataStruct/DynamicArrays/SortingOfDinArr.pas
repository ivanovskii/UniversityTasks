uses crt;

var
  arr: array of integer;
  elem, len: integer;
  f1,f2: text;
  
begin
  assign(f1,'input.txt'); //Связь файла в коде программы и действительного файла на внешнем носителе 
  reset(f1); //Процедура открытия существующего файла для чтения при последовательном доступе
  len:=0;
  while not EOF(f1) do //Функция, возвращающая true если достигнут конец файла
  begin
    readln(f1, elem);
    len+=1;
    if elem = 0 then break;
  end;
  setlength(arr, len-1); //Устанавливаем длину динамического массива (0 в конце - не в счет)
  close(f1);
  reset(f1); //Переоткрываем файл
  for var i:=0 to len-2 do readln(f1, arr[i]);
  arr.Sort;
  assign(f2,'output.txt');  
  rewrite(f2);
  for var i:=0 to len-2 do print(f2, arr[i]);
  close(f1);
  close(f2);  
end.
