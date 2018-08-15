uses crt;

type
  point = record
    x, y: integer;
  end;

var
  points: array [0..1000] of point;
  max: real;
  n: byte;

begin
  read(n);
  for var i := 0 to n - 1 do with points[i] do read(x, y);
  
  for var i := 0 to n - 1 do
    for var j := 0 to n - 2 do
      for var z := 0 to n - 3 do
      begin
        var S := ((points[i].x - points[z].x) * (points[j].y - points[z].y) - (points[j].x - points[z].x) * (points[i].y - points[z].y)) / 2;
        if S > max then max := S;
      end;
  write(max);
end.
