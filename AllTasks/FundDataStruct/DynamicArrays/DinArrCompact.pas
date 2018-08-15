uses crt;

var
  arr: array of integer;
  elem, len, right: integer;
  f1, f2: text;

begin
  assign(f1, 'input.txt'); //Ñâÿçü ôàéëà â êîäå ïðîãðàììû è äåéñòâèòåëüíîãî ôàéëà íà âíåøíåì íîñèòåëå 
  reset(f1); //Ïðîöåäóðà îòêðûòèÿ ñóùåñòâóþùåãî ôàéëà äëÿ ÷òåíèÿ ïðè ïîñëåäîâàòåëüíîì äîñòóïå
  while not EOF(f1) do //Ôóíêöèÿ, âîçâðàùàþùàÿ true åñëè äîñòèãíóò êîíåö ôàéëà
  begin 
    readln(f1, elem);
    if elem = 0 then break;
    len += 1; 
  end;
  len-=1; //len = 4  
  setlength(arr, len+1); //Óñòàíàâëèâàåì äëèíó äèíàìè÷åñêîãî ìàññèâà
  close(f1);
  reset(f1); //Ïåðåîòêðûâàåì ôàéë
  for var i := 0 to len do readln(f1, arr[i]);
  right := len;
  for var i:=0 to (trunc((len-1) div 2)) do
  begin
    arr[i]+=arr[right];
    right-=1;
  end;
  assign(f2, 'output.txt');  
  rewrite(f2);
  for var i := 0 to len-right do print(f2, arr[i]);
  close(f1);
  close(f2);
end.
