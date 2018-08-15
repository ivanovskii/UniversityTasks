uses crt;

type
  PNode = ^Node;
  Node = record
    data: integer;
    next: PNode;
  end;

var
  expr: string;
  S: PNode;
  number, err: integer;

procedure Push(var Head: PNode; x: integer);
var
  NewNode: PNode;
begin
  New(NewNode); //Выделяем память - указываем в памяти на адрес структуры
  NewNode^.data := x; //Записываем значение в указанной памяти
  NewNode^.next := Head; //Сделать первым узлом
  Head := NewNode;
end;

procedure Pop(var Head: PNode);
var
  q: PNode;
begin
  while true do //Цикл нужен для обработки ошибки, если введен '-', когда еще не был создан узел
  begin
    if (Head = nil) then break;
    q := Head; //запомнить вершину
    Head := Head^.next; //удалить вершину из стека
    Dispose(q); //удалить из памяти
    break;
  end;
end;

function isEmpty(S: PNode): Boolean;
begin
  Result := (S = nil);
end;

procedure show(S: PNode);//Вывод данных из стека, начиная с нижнего элемента
var
  i: integer; arr: array of integer;
begin
  i := 0;;
  while S <> nil do
  begin
    setlength(arr, i + 1);
    arr[i] := s^.data;
    s := s^.next;
    i += 1;
  end;
  for i := length(arr) - 1 downto 0 do print(arr[i]);
end;

begin
  S := nil;
  while not EOF(F) do
  begin
    readln(f, expr);
    if (expr[1] = '+') then
    begin
      delete(expr, 1, 1);
      val(expr, number, err);
      if (expr = '') then begin clrscr; continue; end; //Исключает случай, если введен просто плюс
      push(S, number)
    end
    else if (expr[1] = '-') then
    begin
      pop(S);
      if isEmpty(S) then
      begin
        writeln('Стек пуст');
        break;
      end
    end else break;
  end;
  show(S);
end.
