type
  PNode = ^Node;  
  Node = record
    word: string;
    count: integer;
    next: PNode;
  end;

var
  Head: PNode;
  NewNode, q: PNode;
  w: string;
  F: text;
  count: integer;

function GetWord(F: Text): string; //Ôóíêöèÿ ñ÷èòûâàþùàÿ ñëîâî èç ôàéëà
var
  c: char;
begin
  Result := ''; //ïóñòàÿ ñòðîêà
  c := ' '; //ïðîáåë – ÷òîáû âîéòè â öèêë
  while not eof(f) and (c <= ' ') do //ïðîïóñêàåì ñïåöñèìâîëû è ïðîáåëû
    read(F, c);  
  while not eof(f) and (c > ' ') do //÷èòàåì ñëîâî
  begin
    Result += c;
    read(F, c);
  end;
end;

function Find(Head: PNode; NewWord: string): PNode; //Âîçâðàùàåò óêàçàòåëü íà óçåë, â êîòîðîì äàííûå ðàâíû ñòðîêîâîìó ïàðàìåòðó
var
  q: PNode;
begin
  q := Head;
  while (q <> nil) and (NewWord <> q^.word) do
    q := q^.next;
  Result := q;
end;

function CreateNode(NewWord: string): PNode; //Ñîçäàþùàÿ óçåë è âîçâðàùàþùàÿ óêàçàòåëü íà íåãî
var
  NewNode: PNode;
begin
  New(NewNode);
  NewNode^.word := NewWord;
  NewNode^.count := 1;
  NewNode^.next := nil;
  Result := NewNode;
end;

function FindPlace(Head: PNode; NewWord: string): PNode; //Âîçâðàùàåò óêàçàòåëü íà ïîñëåäíèé ýëåìåíò â àëôàâèòíîì ïîðÿäêå
var
  q: PNode;
begin
  q := Head;
  while (q <> nil) and (NewWord > q^.word) do
    q := q^.next;
  Result := q;
end;

procedure AddFirst(var Head: PNode; NewNode: PNode); //Ïðîöåäóðà äîáàâëåíèÿ óçëà â íà÷àëî ñïèñêà
begin
  NewNode^.next := Head;
  Head := NewNode;
end;

procedure AddAfter(p, NewNode: PNode ); //Ïðîöåäóðà äîáàâëåíèå óçëà ïîñëå çàäàííîãî
begin
  NewNode^.next := p^.next;
  p^.next := NewNode;
end;

procedure AddBefore(var Head: PNode; q, NewNode: PNode);
var
  temp: PNode;
begin
  temp := Head;
  if q = Head then
    AddFirst(Head, NewNode )
  else
  begin
    while (temp <> nil) and (temp^.next <> q) do //íàõîäèì ïðåäûäóùèé óçåë
      temp := temp^.next;
    if temp <> nil then AddAfter(temp, NewNode);
  end;
end;

begin
  Head := nil;
  assign(F, 'input.txt' );
  reset(F);
  while not eof(f) do
  begin
    w := GetWord(F);
    if w = '' then break;
    q := Find(Head, w);
    if q <> nil then
      q^.count := q^.count + 1
    else
    begin
      NewNode := CreateNode(w);
      q := FindPlace(Head, w);
      AddBefore(Head, q, NewNode);
    end;
  end;
  q := Head; 
  count := 0;
  while q <> nil do 
  begin
    writeln(q^.word, ': ', q^.count);
    q := q^.next;  
  end;
end.
