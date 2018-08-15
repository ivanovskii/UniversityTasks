uses crt;

type
  participant = record
    fname, name: string;
    point: integer;
  end;

var
  competition: array [0..1000] of participant; //Ìàññèâ ó÷àñòíèêîâ
  f1, f2: text;
  time, err, i, k, count: integer;
  str: string;

begin
  i := 0; count:=0;
  assign(f1, 'input.txt');
  reset(f1);
  assign(f2, 'output.txt');
  rewrite(f2);
  readln(f1, k);
  while not EOF(f1) do //
  begin
    readln(f1, str); //Ñ÷èòûâàåì ñòðîêó
    competition[i].name := copy(str, 1, pos(' ', str)); //Çàïîìèíàåì èìÿ
    delete(str, 1, length(competition[i].name)); //Óäàëÿåì èç ñòðîêè
    competition[i].fname := copy(str, 1, pos(' ', str));
    delete(str, 1, length(competition[i].fname));
    val(str, competition[i].point, err); //Ïðåîáðàçóåì îñòàâøóþñÿ ÷àñòü ñòðîêè â ÷èñëî è çàïîìèíàåì êàê î÷êè
    i += 1;
  end;
  
  for var h := 0 to i - 1 do //Ñîðòèðîâêà ïî âîçðàñòàíèþ ïóçûðüêîì ïî î÷êàì
    for var j := 0 to i - 2 - h do
      if competition[j].point > competition[j + 1].point then
      begin
        time := competition[j].point;
        competition[j].point := competition[j + 1].point;
        competition[j + 1].point := time;
        
        var tStr: string := competition[j].name;
        competition[j].name := competition[j + 1].name;
        competition[j + 1].name := tStr;
        
        tStr := competition[j].fname;
        competition[j].fname := competition[j + 1].fname;
        competition[j + 1].fname := tStr;
        
      end;
  
  for var b := 0 to i - 1 do if competition[b].point > k then count+=1;
  writeln(f2, count);
  count:=0;
  for var b := 0 to i - 1 do
  begin
    if competition[b].point > k then
    begin
      count+=1;
      writeln(f2, count, ') ', competition[b].fname[1], '. ', competition[b].name, competition[b].point)
    end;
  end;
  close(f1);
  close(f2);
end.
