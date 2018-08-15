var
  desk: array [1..8, 'a'..'h'] of char;
  x: char;
  y: byte;

function diag(i: byte; j: char): boolean;
var
  logic: boolean; count: integer;
begin
  while count <> 7 do
  begin
    count += 1;
    if (chr(ord(x) - count) = j) and (y - count = i)
    or (chr(ord(x) + count) = j) and (y + count = i)
    or (chr(ord(x) + count) = j) and (y - count = i)
    or (chr(ord(x) - count) = j) and (y + count = i) 
    then logic := true
  end;
  diag := logic;
end;

begin
  read(x, y);
  y := 9 - y;
  for var i := 1 to 8 do
  begin
    if i>=2 then writeln;
    for  var j := 'a' to 'h' do
    begin
      if (x = j) and (y = i) then desk[i, j] := 'Q'
      else if  (x = j) or (y = i) or diag(i, j) then desk[i, j] := '*'
      else desk[i, j] := '.';
      print(desk[i, j]);
    end;
  end;
end.