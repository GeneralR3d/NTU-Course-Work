import sense_hat
sense = sense_hat.SenseHat()
sense.set_rotation(180)

def get_colour(colour_channel):
    tries = 1
    while tries <=3:
        try:
            colour_value = int(input("Enter the value of {} colour for message (0 to 255): ".format(colour_channel)))
        except ValueError:
            print("Invalid: enter integer only!",end=" ")
            print("Try number : {}".format(tries))
            tries+=1
        else:
            if 0<=colour_value<=255:
                print("*****The value of {} is {}******".format(colour_channel,colour_value),end=" ")
                print("Try number : {}".format(tries))
                break
            else:
                print("Invalid: the value has to be between 0 and 255",end=" ")
                print("Try number : {}".format(tries))
                tries += 1
    else:
        colour_value = 0
        print("*****The value of {} is {} ******".format(colour_channel,colour_value))
    
    return colour_value
    

