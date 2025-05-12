.MODEL SMALL
.STACK 1000H
.DATA
M1 DB 10,13,10,13,'   **Chao mung den voi cua hang cua chung toi!**$',10,13 
M2 DB 10,13,10,13,'Nhap lua chon cua ban: $'

M3 DB 10,13,'  **                 1.Bua sang                **$' 
M4 DB 10,13,'  **                 2.Bua trua                **$'
MS5 DB 10,13,'  **                 3.Bua toi                 **$'
               
               
M8 DB 10,13,10,13,'***Vui long chon mon an***$'
  
;BREAKFAST  
M9 DB 10,13,'  **           1.Pho                     35/-                      **$' 
M10 DB 10,13,'  **           2.Banh mi                 10/-                      **$'
M11 DB 10,13,'  **           3.Pho cuon                40/-                      **$'
M12 DB 10,13,'  **           4.Banh xeo                10/-                      **$'
M13 DB 10,13,'  **           5.Banh cuon               25/-                      **$' 

 

;Lunch 

M25 DB 10,13,'  **  1.Com thit xao hanh tay                  45/-                **$' 
M26 DB 10,13,'  **  2.Bun cha                                35/-                **$' 
M27 DB 10,13,'  **  3.Bun ca                                 35/-                **$' 
M28 DB 10,13,'  **  4.Bun dau                                35/-                **$'
M29 DB 10,13,'  **  5.Nem nuong                              35/-                **$'
 

 
 
;DINNER

M18 DB 10,13,'  **  1.Com tam                 40/-                               **$'
M19 DB 10,13,'  **  2.Com rang dua bo         25/-                               **$'
M20 DB 10,13,'  **  3.Bun bo Hue              35/-                               **$' 
M21 DB 10,13,'  **  4.Mi xao cai bo           35/-                               **$'
M22 DB 10,13,'  **  5.Lau                     150/-                               **$'
 
;DRINK MENU
M70 DB 10,13,'***Vui long chon nuoc uong***$'
M71 DB 10,13,'  **                  1.Tra da        5/-                          **$'
M72 DB 10,13,'  **                  2.Nuoc ngot    10/-                          **$'
M73 DB 10,13,'  **                  3.Cafe         15/-                          **$'
M74 DB 10,13,'  **                  4.Sua tuoi     12/-                          **$'
M75 DB 10,13,'  **                  5.Khong chon                                 **$'
M76 DB 10,13,'Nhap nuoc uong cua ban: $'

TotalFoodPrice DW 0
TotalDrinkPrice DW 0


;INVALID
M55 DB 10,13,10,13,'***&&Khong hop le&&***$'
M56 DB 10,13,'***&&Vui long nhap lai&&***$'



M57 DB 10,13,10,13,'Nhap mon an cua ban: $'
M58 DB 10,13,'So luong: $'
M59 DB 10,13,'Tong gia tien: $'


DRINK DB ?
QUANTITY DB ?


M60 DB 10,13,10,13,'1.Quay lai Menu chinh$'
M61 DB 10,13,'2.Roi di$'



MR1 DB 10,13,'  **                                           **$'
MR2 DB 10,13,'  ***********************************************$'

MR3 DB 10,13,'  **                                           **$'


MR4 DB 10,13,'  **                                                               **$'
MR5 DB 10,13,'  *******************************************************************$'



MR6 DB 10,13,'  **                                          **$'
MR7 DB 10,13,'  **********************************************$'


SEJ DB 10,13,10,13,' $'

.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
  TOP:
  
    LEA DX,M1
    MOV AH,9
    INT 21H
    
    LEA DX,SEJ 
    MOV AH,9
    INT 21H
    
    LEA DX,MR2
    MOV AH,9
    INT 21H
       
    LEA DX,MR2
    MOV AH,9
    INT 21H     
    
    LEA DX,MR3
    MOV AH,9
    INT 21H   
       
    
    LEA DX,M3
    MOV AH,9
    INT 21H
    
    LEA DX,M4
    MOV AH,9
    INT 21H
    
    LEA DX,MS5
    MOV AH,9
    INT 21H
    
    
    LEA DX,MR1
    MOV AH,9
    INT 21H
    
    LEA DX,MR2
    MOV AH,9
    INT 21H
    
    LEA DX,MR2
    MOV AH,9
    INT 21H
    
   NHAP_LAI:
    
    LEA DX,M2
    MOV AH,9
    INT 21H
    
          
    MOV AH,1
    INT 21H
    MOV BH,AL
    SUB BH,48
    
    CMP BH,1
    JE BREAKFAST
    
    CMP BH,2
    JE LUNCH   
     
    CMP BH,3
    JE DINNER 
    
    
    LEA DX, M55
    MOV AH, 9
    INT 21H
    
    LEA DX, M56
    MOV AH, 9
    INT 21H
    
    JMP NHAP_LAI
    
          
   BREAKFAST:   ;BREAKFAST
    
    
    LEA DX,M8    
    MOV AH,9
    INT 21H
    
    LEA DX,SEJ 
    MOV AH,9
    INT 21H
    
    LEA DX,MR5
    MOV AH,9
    INT 21H
    
    
    LEA DX,MR5
    MOV AH,9
    INT 21H
    
    LEA DX,MR4
    MOV AH,9
    INT 21H
   
    LEA DX,M9    
    MOV AH,9
    INT 21H 
    
    
    LEA DX,M10   
    MOV AH,9
    INT 21H
    
    LEA DX,M11
    MOV AH,9          
    INT 21H 
    
    LEA DX,M12
    MOV AH,9           
    INT 21H
    
    
    LEA DX,M13         
    MOV AH,9
    INT 21H
    
    
    LEA DX,MR4
    MOV AH,9
    INT 21H
    
    LEA DX,MR5
    MOV AH,9
    INT 21H
    
    
    LEA DX,MR5
    MOV AH,9
    INT 21H
    
   LAP_SANG:       ;LAP NEU NHAP VAO KO HOP LE
    LEA DX,M57              
    MOV AH,9
    INT 21H 
    
    
    MOV AH,1
    INT 21H
    MOV BL,AL
    SUB BL,48 
    
    CMP BL,1
    JE THIRTYFINE
    
    CMP BL,2
    JE TEN
    
    CMP BL,3
    JE FOURTY 
    
    CMP BL,4
    JE TEN
    
    CMP BL,5
    JE TWENTYFIVE
    
       
    LEA DX, M55
    MOV AH, 9
    INT 21H
    
    LEA DX, M56
    MOV AH, 9
    INT 21H
    
    JMP LAP_SANG
    
   THIRTYFINE:
   
   
    MOV BL,35
    
    LEA DX,M58              
    MOV AH,9
    INT 21H 
    
    MOV TotalDrinkPrice, 0       
    MOV AH,1
    INT 21H
    SUB AL,48
    MUL BL                      
    MOV TotalFoodPrice, AX      
    JMP CHONNUOC
    
        
   FOURTYFINE:
   
   
    MOV BL,45
    
    LEA DX,M58              
    MOV AH,9
    INT 21H 
    
    MOV TotalDrinkPrice, 0       
    MOV AH,1
    INT 21H
    SUB AL,48
    MUL BL                      
    MOV TotalFoodPrice, AX      
    JMP CHONNUOC
   FOURTY:
    MOV BL,40
    
    LEA DX,M58              
    MOV AH,9
    INT 21H 
    
    MOV TotalDrinkPrice, 0       
    MOV AH,1
    INT 21H
    SUB AL,48
    MUL BL                      
    MOV TotalFoodPrice, AX      
    JMP CHONNUOC
   FIFTY:
    MOV BL,50
    
    LEA DX,M58              
    MOV AH,9
    INT 21H 
    
    MOV TotalDrinkPrice, 0       
    MOV AH,1
    INT 21H
    SUB AL,48
    MUL BL                      
    MOV TotalFoodPrice, AX      
    JMP CHONNUOC
   SEVENTY:
    MOV BL,70
    
    LEA DX,M58              
    MOV AH,9
    INT 21H 
    
    MOV TotalDrinkPrice, 0       
    MOV AH,1
    INT 21H
    SUB AL,48
    MUL BL                      
    MOV TotalFoodPrice, AX      
    JMP CHONNUOC
   EIGHTY:
    MOV BL,80
    
    LEA DX,M58              
    MOV AH,9
    INT 21H 
    
    MOV TotalDrinkPrice, 0       
    MOV AH,1
    INT 21H
    SUB AL,48
    MUL BL                      
    MOV TotalFoodPrice, AX      
    JMP CHONNUOC
   TWENTYFIVE:
    MOV BL,25
    
    LEA DX,M58              
    MOV AH,9
    INT 21H 
    
    MOV TotalDrinkPrice, 0       
    MOV AH,1
    INT 21H
    SUB AL,48
    MUL BL                      
    MOV TotalFoodPrice, AX      
    JMP CHONNUOC    
    
   LUNCH:
                    ;LUNCH
    LEA DX,M8
    MOV AH,9
    INT 21H
     
    
    LEA DX,SEJ 
    MOV AH,9
    INT 21H
     
    LEA DX,MR5
    MOV AH,9
    INT 21H
    
     
    LEA DX,MR5
    MOV AH,9
    INT 21H
                  
    LEA DX,MR4
    MOV AH,9
    INT 21H
        
    
    LEA DX,M25               
    MOV AH,9
    INT 21H 
    
    LEA DX,M26               
    MOV AH,9
    INT 21H
    
    LEA DX,M27               
    MOV AH,9
    INT 21H  
    
    LEA DX,M28              
    MOV AH,9
    INT 21H 
    
    LEA DX,M29            
    MOV AH,9
    INT 21H                        
    
      
    LEA DX,MR4
    MOV AH,9
    INT 21H
                    
    LEA DX,MR5
    MOV AH,9
    INT 21H
    
    
    LEA DX,MR5
    MOV AH,9
    INT 21H 
    
   LAP_TRUA:     ;LAP NEU NHAP VAO KO HOP LE
   
    LEA DX,M57              
    MOV AH,9
    INT 21H 
    
    
    MOV AH,1
    INT 21H
    MOV BL,AL
    SUB BL,48 
    
    CMP BL,1
    JE FOURTYFINE
    
    CMP BL,2
    JE THIRTYFINE
    
    CMP BL,3
    JE THIRTYFINE
    
    CMP BL,4
    JE THIRTYFINE
    
    CMP BL,5
    JE THIRTYFINE
    
    
    LEA DX, M55
    MOV AH, 9
    INT 21H
    
    LEA DX, M56
    MOV AH, 9
    INT 21H
    
    JMP LAP_TRUA
    
   TEN:
    
    MOV BL,10                
    LEA DX,M58               
    MOV AH,9
    INT 21H

    MOV AH,1
    INT 21H
    SUB AL,48
    MOV BH,AL
    MOV AL,BL
    MUL BH                  
    MOV TotalFoodPrice, AX  

    
    JMP CHONNUOC

   TWENTY:
   
    MOV BL,20                 
    LEA DX,M58               
    MOV AH,9
    INT 21H

    MOV AH,1
    INT 21H
    SUB AL,48
    MOV BH,AL
    MOV AL,BL
    MUL BH                   
    MOV TotalFoodPrice, AX   

    
    JMP CHONNUOC

    
   THIRTY:
   
    MOV BL,30
    
    LEA DX,M58              
    MOV AH,9
    INT 21H 
    
    MOV TotalDrinkPrice, 0       
    MOV AH,1
    INT 21H
    SUB AL,48
    MUL BL                      
    MOV TotalFoodPrice, AX      
    JMP CHONNUOC
   SIXTY: 
    MOV BL,60
    
    LEA DX,M58              
    MOV AH,9
    INT 21H 
    
    MOV TotalDrinkPrice, 0       
    MOV AH,1
    INT 21H
    SUB AL,48
    MUL BL                      
    MOV TotalFoodPrice, AX      
    JMP CHONNUOC
   NINETY:
    MOV BL,90
    
    LEA DX,M58              
    MOV AH,9
    INT 21H 
    
    MOV TotalDrinkPrice, 0       
    MOV AH,1
    INT 21H
    SUB AL,48
    MUL BL                      
    MOV TotalFoodPrice, AX      
    JMP CHONNUOC
  DINNER:
    LEA DX,M8
    MOV AH,9         ;DINNER 
    INT 21H
    
    LEA DX,SEJ
    MOV AH,9
    INT 21H
    
    
    LEA DX,MR5
    MOV AH,9
    INT 21H
    
    LEA DX,MR5
    MOV AH,9
    INT 21H     
    
    LEA DX,MR4
    MOV AH,9
    INT 21H
    
       
    LEA DX,M18        
    MOV AH,9
    INT 21H 
    
    LEA DX,M19
    MOV AH,9         
    INT 21H
    
    
    LEA DX,M20         
    MOV AH,9
    INT 21H
    
    LEA DX,M21
    MOV AH,9               
    INT 21H  
    
    
    LEA DX,M22             
    MOV AH,9
    INT 21H 
    
    
    LEA DX,MR4
    MOV AH,9
    INT 21H
    
    LEA DX,MR5   
    MOV AH,9
    INT 21H
    
    
    LEA DX,MR5
    MOV AH,9
    INT 21H   
    
    
   LAP_TOI:
    
    LEA DX,M57              
    MOV AH,9
    INT 21H 
    
    
    MOV AH,1
    INT 21H
    MOV BL,AL
    SUB BL,48 
    
    CMP BL,1
    JE FOURTY
    
    CMP BL,2
    JE TWENTYFIVE
    
    CMP BL,3
    JE THIRTYFINE 
    
    CMP BL,4
    JE THIRTYFINE
    
    CMP BL,5
    JE ONEHUNDRED_FIFTY
    
    LEA DX, M55
    MOV AH, 9
    INT 21H
    
    LEA DX, M56
    MOV AH, 9
    INT 21H
    
    JMP LAP_TOI 
    
   ONEHUNDRED_FIFTY:  
    MOV BL,150
    
    LEA DX,M58              
    MOV AH,9
    INT 21H 
    
    MOV TotalDrinkPrice, 0       
    MOV AH,1
    INT 21H
    SUB AL,48
    MUL BL                      
    MOV TotalFoodPrice, AX      
    JMP CHONNUOC
    
   CHONNUOC:
    LEA DX, M70
    MOV AH, 9
    INT 21H
    
    LEA DX, SEJ
    MOV AH, 9
    INT 21H
    LEA DX, MR5
    MOV AH, 9
    INT 21H
    LEA DX, MR5
    MOV AH, 9
    INT 21H
    LEA DX, MR4
    MOV AH, 9
    INT 21H
    
    LEA DX, M71
    MOV AH, 9
    INT 21H
    LEA DX, M72
    MOV AH, 9
    INT 21H
    LEA DX, M73
    MOV AH, 9
    INT 21H
    LEA DX, M74
    MOV AH, 9
    INT 21H
    LEA DX, M75
    MOV AH, 9
    INT 21H
    
    LEA DX, MR4
    MOV AH, 9
    INT 21H
    LEA DX, MR5
    MOV AH, 9
    INT 21H
    LEA DX, MR5
    MOV AH, 9
    INT 21H
    
   LAP_NUOC:
    LEA DX, M76
    MOV AH, 9
    INT 21H


    MOV AH, 1
    INT 21H
    SUB AL, 48
    MOV BL, AL 

    CMP BL, 5
    JE CALCULATE_TOTAL  

    CMP BL, 1
    JE DRINK5
    CMP BL, 2
    JE DRINK10
    CMP BL, 3
    JE DRINK15
    CMP BL, 4
    JE DRINK12  
    
    LEA DX, M55
    MOV AH, 9
    INT 21H
    
    LEA DX, M56
    MOV AH, 9
    INT 21H

    JMP LAP_NUOC

    DRINK5: MOV BL, 5  
    JMP DRINK_PROCESS
    DRINK10: MOV BL, 10 
    JMP DRINK_PROCESS
    DRINK15: MOV BL, 15 
    JMP DRINK_PROCESS
    DRINK12: MOV BL, 12 
    JMP DRINK_PROCESS
    
    
    DRINK_PROCESS:
    LEA DX, M58
    MOV AH, 9
    INT 21H

    MOV AH, 1
    INT 21H
    SUB AL, 48
    MUL BL
    MOV TotalDrinkPrice, AX

  
    CALCULATE_TOTAL:

    MOV AX, TotalFoodPrice
    ADD AX, TotalDrinkPrice

    
    MOV CX, 10
    XOR DI, DI
    CONV_LOOP:
        XOR DX, DX
        DIV CX
        ADD DL, '0'
        PUSH DX
        INC DI
        CMP AX, 0
    JG CONV_LOOP
    
    
    LEA DX,M59
    MOV AH,9
    INT 21H
    
    PRINT_LOOP:
        POP DX
        MOV AH, 2
        INT 21H
        DEC DI
        JNZ PRINT_LOOP

    ;FOR /- PRINT
    MOV DL,47
    INT 21H
    MOV DL,45
    INT 21H
     
     
    LEA DX,M60
    MOV AH,9
    INT 21H
    
    LEA DX,M61
    MOV AH,9
    INT 21H
    
    LEA DX,M2
    MOV AH,9
    INT 21H 
    
    MOV AH,1
    INT 21H
    SUB AL,48
    
        
    CMP AL,1
    JE TOP
    
    JMP EXIT     
    
    
     EXIT:
    
    MOV AH,4CH
    INT 21H
    MAIN ENDP
END MAIN