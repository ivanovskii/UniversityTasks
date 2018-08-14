uses crt;

type
  st = set of char;
  rk = set of char;

type
  PNode = ^Node;
  Node = record
    data: string;
    prev, next: PNode;
  end;
  Queue = record
    head, tail: PNode;
  end;

var
  symbol: char;
  expr: string;
  Q: Queue;
  S: PNode;
  suit: st := ['D', 'S', 'H', 'C']; //множество мастей для проверки expr
  rank: rk := ['2'..'9', 'A', 'T', 'J', 'Q', 'K'];//множество рангов
  errMessage, errMessage2: string;

procedure Push(var head: PNode; var Q: Queue; x: string);//Втокнуть в начало
var
  NewNode: PNode;
begin
  New(NewNode); //Выделяем память - указываем в памяти на адрес структуры
  NewNode^.data := x; //Записываем значение в указанной памяти
  NewNode^.next := nil;
  if Q.tail <> nil then Q.tail^.next := NewNode;
  Q.tail := NewNode;
  if Q.head = nil then Q.head := Q.tail;
  NewNode^.prev := Head;
  Head := NewNode;
end;

procedure Pop(var Head: PNode; var  Q: queue); //Убрать с начала
var 
  temp: PNode;
begin
  temp:=q.tail;
  if (q.head <> nil) then
    if (q.head^.next <> nil) then
    begin
      head:=q.tail^.prev;
      head^.next:=nil;
      q.tail:=head;
    end
    else
    begin
      q.tail := nil;
      q.head := nil;
    end;
  Dispose(temp);
end;

procedure PushTail(var Head:PNode; var Q: Queue; x: string);//Втолкнуть в конец
var
  NewNode: PNode;
begin
  New(NewNode);
  NewNode^.data := x;
  NewNode^.prev := nil;
  if q.head <> nil then
  begin
    NewNode^.next := Q.head;
    Q.head^.prev := NewNode;
    Q.head := NewNode;
  end
  else
  begin
    NewNode^.next := nil;
    Q.tail := NewNode;
    Q.head := Q.tail;
    Head := NewNode;
  end;
end;

procedure PopTail(var Q: Queue); //Убрать с конца
var temp: PNode;
begin
  temp := Q.head;
  if (q.tail <> nil) and (q.head <> nil) then
  begin
    Q.head := temp^.next;
    if q.head <> nil then Q.head^.prev := nil;
  end;
  if Q.head = nil then Q.tail := nil;
  Dispose(temp);
end;

function IsEmpty(Q: Queue): Boolean;
begin
  Result := ((q.tail = nil) and (q.head = nil));
end;

procedure show(Q: Queue);//Вывод данных дека
var
  i: integer;
begin
  i := 0;
  while Q.tail <> nil do
  begin
    print(Q.tail^.data);
    q.tail := q.tail^.prev;
    i += 1;
  end;
end;

procedure del2line;//Удаляет две предыдущие линии
begin
  gotoXY(1, whereY - 1);
  clearline;
  gotoXY(1, whereY - 1);
  clearline;
end;

function check(expr: string): boolean;//Проверят, верно ли введены названия карт
var
  test1, test2: boolean;
begin
  test1 := false;
  test2 := false;
  if (length(expr) = 2) then
  begin
    if expr[1] in suit then test1 := true;
    if expr[2] in rank then test2 := true;
    if not (test1 and test2) then result := false else result := true;
  end
  else result := false;
end;

procedure delSymbol;//Удаляет первый символ в строке
begin
  delete(expr, 1, 1);
end;

procedure information;//Выводит информацию о консольном приложении по вводу 0
begin
  clrscr;
  writeln('Данная программа моделирует колоду карт.');
  writeln(#10, 'Для управления колодой используется 4 команды:');
  writeln('1) +<карта> – добавить карту на верх колоды');
  writeln('2) ^ – снять верхнюю карту колоды');
  writeln('3) #<карта> – добавить карту на дно колоды');
  writeln('4) / – удалить нижнюю карту колоды');
  writeln(#10, 'Добавляемая карта обозначается кодом, состоящим из масти и ранга карты:', #10, ' <масть><ранг>');
  writeln(#10, 'Масть – это одна буква из след+ующего набора:'#10, ' "C" (трефы, Clubs)');
  writeln(' "S" (пики, Spades)', #10, ' "H" (червы, Hearts)', #10, ' "D" (бубны, Diamonds)');
  writeln(#10, 'Ранг карты тоже обозначается одним знаком:');
  writeln(' A – туз (Ace)', #10, ' 2-9 – карты ранга от 2 до 9 обозначаются цифрой', #10, ' T – десятка (ten)');
  writeln(' J – валет (Jack)', #10, ' Q – дама (Queen)', #10, ' K – король (King)');
  writeln(#10, #10, 'ООО "CCD Software inc". Все права защищены.');
  write(#10, #10, 'Нажмите любую клавишу для продолжения ');
  readkey;
  clrscr;
end;

begin
  errMessage := 'Ошибка. Нажмите любую клавишу для продолжения';
  errMessage2 := 'Входные данные неверные. Для выхода нажмите "1". Для помощи "0". Чтобы продолжить - любую клавишу';
  Q.tail := nil;
  Q.head := nil;
  S := nil;
  while true do
  begin
    readln(expr);
    if (expr = '') then begin continue end; //Ловит ошибку с enter
    symbol := expr[1];
    case symbol of
      '+': 
        begin
          delSymbol;
          if not (check(expr)) then //Проверка на существование введенной карты
          begin
            writeln(errMessage);
            readkey;
            del2line;
            continue
          end;
          push(S, Q, expr)
        end;
      '^':
        begin
          pop(S, Q);
          if IsEmpty(Q) then
          begin
            writeln('Дек пуст');
            break;
          end
        end;
      '#': 
        begin
          delSymbol;
          if not (check(expr)) then //Проверка на существование введенной карты
          begin
            writeln(errMessage);
            readkey;
            del2line;
            continue
          end;
          pushTail(S, Q, expr)
        end;
      '/':
        begin
          popTail(Q);
          if  IsEmpty(Q) then
          begin
            writeln('Дек пуст');
            break;
          end
        end;
      '0': information;
      '1': break;
    else 
      begin
        writeln(errMessage2);
        readkey;
        del2line;
      end;
    end;
  end;
  show(q);
end.
