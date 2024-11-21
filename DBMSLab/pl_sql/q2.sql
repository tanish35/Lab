DECLARE
    input_char CHAR(1); 
BEGIN
    input_char := 'b';

   
    input_char := UPPER(input_char);

   
    IF input_char IN ('A', 'E', 'I', 'O', 'U') THEN
        DBMS_OUTPUT.PUT_LINE('The character is a vowel: ' || input_char);
    ELSE
        DBMS_OUTPUT.PUT_LINE('The character is NOT a vowel: '|| input_char);
    END IF;
END;

