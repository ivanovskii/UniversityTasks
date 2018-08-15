uses crt;

var
  points, name, fname, str: string;
  f1, f2: text;
  count:byte;
  n, err, k:integer;
  
begin
  assign(f1, 'input.txt');
  reset(f1);
  assign(f2, 'output.txt');
  rewrite(f2);
  readln(f1, k);
  while not EOF(f1) do
  begin
    readln(f1, str); //Считываем строку
    fname:=copy(str, 1, pos(' ', str)); //Запоминаем фамилию
    delete(str, 1, length(fname)); //Удаляем из строки
    name:=copy(str, 1, pos(' ', str));
    delete(str, 1, length(name));
    val(str, n, err);
    if (n > k) then
    begin
      count+=1;
      writeln(f2, count, ') ', fname, name);     
    end
  end;
  writeln(f2, count);
  close(f1);
  close(f2);
end.