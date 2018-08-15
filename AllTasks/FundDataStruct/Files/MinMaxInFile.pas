uses crt;

var
  elem, max, min: integer;
  flag: boolean;
  f1, f2: text;

begin
  flag := true;
  assign(f1, 'input.txt');
  assign(f2, 'output.txt');
  reset(f1);
  rewrite(f2);
  max := 0;
  min := 0;
  while not EOF(f1) do
  begin
    readln(f1, elem);
    if elem = 0 then break;
    if (elem mod 2 = 0) and (elem > 0) then
    begin
      if (elem >= max) then max := elem;
      if (elem <= min) or (flag = true) then begin min := elem; flag := false end;
    end;
  end;
  if (max = 0) then writeln(f2, 0) else print(f2, max, min);
  close(f1);
  close(f2);
end.
