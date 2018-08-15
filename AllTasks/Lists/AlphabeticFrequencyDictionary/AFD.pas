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

function GetWord(F: Text): string;
var
  c: char;
begin
  Result := '';
  c := ' ';
  while not eof(f) and (c <= ' ') do
    read(F, c);  
  while not eof(f) and (c > ' ') do
  begin
    Result += c;
    read(F, c);
  end;
end;

function Find(Head: PNode; NewWord: string): PNode;
var
  q: PNode;
begin
  q := Head;
  while (q <> nil) and (NewWord <> q^.word) do
    q := q^.next;
  Result := q;
end;

function CreateNode(NewWord: string): PNode;
var
  NewNode: PNode;
begin
  New(NewNode);
  NewNode^.word := NewWord;
  NewNode^.count := 1;
  NewNode^.next := nil;
  Result := NewNode;
end;

function FindPlace(Head: PNode; NewWord: string): PNode;
var
  q: PNode;
begin
  q := Head;
  while (q <> nil) and (NewWord > q^.word) do
    q := q^.next;
  Result := q;
end;

procedure AddFirst(var Head: PNode; NewNode: PNode);
begin
  NewNode^.next := Head;
  Head := NewNode;
end;

procedure AddAfter(p, NewNode: PNode );
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
    while (temp <> nil) and (temp^.next <> q) do
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
