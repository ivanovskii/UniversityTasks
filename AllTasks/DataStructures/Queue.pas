uses crt;

type
  PNode = ^Node;
  Node = record
    data: integer;
    next: PNode;
  end;
  Queue = record
    head, tail: PNode;
  end;
  
var
  expr: string;
  Q: Queue;
  number, err: integer;
  f: text;

procedure PushTail(var Q: Queue; x: integer);
var NewNode: PNode;
begin
  New(NewNode);
  NewNode^.data := x;
  NewNode^.next := nil;
  if Q.tail <> nil then Q.tail^.next := NewNode;
  Q.tail := NewNode;
  if Q.head = nil then Q.head := Q.tail;
end;

function Pop (var Q: Queue): integer;
var top: PNode;
begin
  if Q.head = nil then begin
    result := MaxInt;
    exit;
  end;
  top := Q.head;
  Result := top^.data;
  Q.head := top^.next;
  if Q.head = nil then Q.tail := nil;
  Dispose(top);
end;

function isEmpty(Q: Queue): Boolean;
begin
  Result := (Q.head = nil);
end;

procedure show(Q: Queue);//Вывод данных из стека, начиная с нижнего элемента
var
  i: integer;
begin
  i := 0;
  while Q.head <> nil do
  begin
    print(Q.head^.data);
    Q.head := Q.head^.next;
    i += 1;
  end;
end;

begin
  assign(f, 'input2.txt');
  reset(f);
  Q.tail:= nil;
  Q.head:= nil;
  while true do
  begin
    readln(expr);
    if (expr[1] = '+') then
    begin
      delete(expr, 1, 1);
      val(expr, number, err);
      if (expr = '') then begin clrscr; continue; end; //Исключает случай, если введен просто плюс
      pushtail(Q, number)
    end
    else if (expr[1] = '-') then
    begin
      pop(Q);
      if isEmpty(Q) then
      begin
        writeln('Очередь пуста');
        break;
      end
    end else break;
  end;
  show(Q);
  close(f);
end.
