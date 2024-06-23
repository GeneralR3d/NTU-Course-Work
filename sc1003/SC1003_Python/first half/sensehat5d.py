import sense_hat, time, random


red=(255,0,0)
green=(0,255,0)
blue=(0,0,255)
yellow=(255,255,0)
white=(255,255,255)
black=(0,0,0)
orange=(255,165,0)
    
def main():
    display = sense_hat.SenseHat()
    random.seed()
    
    
    
    white_arrow = [black,black,black,black,black,black,black,black,
                    black,black,black,white,black,black,black,black,
                    black,black,white,white,white,black,black,black,
                    black,white,black,white,black,white,black,black,
                    black,black,black,white,black,black,black,black,
                    black,black,black,white,black,black,black,black,
                    black,black,black,white,black,black,black,black,
                    black,black,black,black,black,black,black,black]
                    
    
    yellow_arrow = colourchanger(white_arrow,*yellow)#need to unpack the tuple
    red_arrow = colourchanger(white_arrow,*red)#need to unpack the tuple
    
    #display.set_pixels(red_arrow)
    #for i in range(5):
        #display.set_pixels(yellow_arrow)
        #time.sleep(10)
        #display.set_pixels(red_arrow)\
    while True:    
        orientation = (0,90,180,270)
        
        orient = random.randint(0,3)
        
    
        
        
        
        if orient == 0:
            target = (0,-1,-0)
        elif orient == 1:
            target = (1.0,0,0)
        elif orient == 2:
            target = (0,1,0)
        else:
            target = (-1,0,-0)
            
        
        display.set_rotation(orientation[orient])
        display.set_pixels(yellow_arrow)
        
        wrong_counter=0
        while wrong_counter<5:
            
            acceleration = display.get_accelerometer_raw()
            x=round(acceleration['x'],0)
            y=round(acceleration['y'],0)
            z=round(acceleration['z'],0)
            
            if (x,y,z)==(target):
                time.sleep(1)
                break
            else:
                time.sleep(1)
                wrong_counter += 1
        else:
            display.set_pixels(red_arrow)
            exit()
    
    
        
        
    
    
    
    
    
    


def colourchanger(orig,r,g,b):
    """
    changes all pixels that are not black to target colour
    """
    new=[]
    for pixel in orig:
        if pixel != black:
            pixel = (r,g,b)
            
        new.append(pixel)
    return new
    
if __name__ == "__main__":
    main()
    