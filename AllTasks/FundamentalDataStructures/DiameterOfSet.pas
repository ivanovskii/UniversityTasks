uses crt;

type
  point = record
    x, y: integer
  end;

var
  points: array [0..10000] of point;
  n: byte;
  max: real;

begin
  read(n);
  for var i := 0 to n - 1 do with points[i] do read(x, y); //Заполняем массив структур
  for var i := 0 to n - 1 do 
    for var j := 0 to n - 2 do
    begin
      var dist := sqrt(sqr(points[i].x - points[j].x) + (sqr(points[i].y - points[j].y))); //Перебираем все точки, находим максимальное расстояние
      if dist > max then max := dist;
    end;
  write(max);
end.
