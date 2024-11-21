DECLARE
    a NUMBER ;
    b NUMBER;
    c char(1);
    ans NUMBER;
BEGIN
  a:=50;
  b:=10;
  c:='*';
  IF c='+' THEN
    ans:=a+b;
  ELSIF c='-' THEN
    ans:=a-b;
  ELSIF c='/' THEN
    ans:=a/b;
  ELSE
    ans:=a*b;
  END IF;
  dbms_output.put_line('The ans is '||ans);
END;

