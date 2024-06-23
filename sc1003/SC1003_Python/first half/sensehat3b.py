import sense_hat

def main():
    display= sense_hat.SenseHat()
    
    display.set_rotation(90)
    display.show_message("Hi welcome to my class",scroll_speed=0.03,back_colour=(255,0,0))
    
    word = input("Enter what you want to say: ")
    
    while True:
        speed = input("Enter speed(from 0.01 to 0.1): ")
        
        speed = validateInt(speed,0.01,0.1)
        if speed != False:
            break
    
    while True:
        backR = input("Enter red channel of back colour(from 0 to 255): ")
        
        backR = validateInt(backR,0,255)
        if backR != False:
            break
    
    while True:
        backG = input("Enter green channel of back colour(from 0 to 255): ")
    
        backG = validateInt(backR,0,255)
        if backG != False:
            break
    
   
    while True:
        backB = input("Enter blue channel of back colour(from 0 to 255): ")
        
        backB = validateInt(backB,0,255)
        if backB != False:
            break
    
    display.show_message(word,scroll_speed=speed,back_colour=(backR,backG,backB))
        
        

def validateInt(value,lowerInclusive,upperInclusive):
    """
    converts string to float and check whether is between lower and upper bounds. If yes return the converted int, else return false
    """
    try:
        value = float(value)
        
            
    except ValueError:
        return False
        
    else:
        if lowerInclusive<= value <= upperInclusive:
            return value
        else:
            return False
        
        
        
        
if __name__ == "__main__":
    main()
        

        
        
        
        
        
        
        
        
        
        
        
        
        
        



