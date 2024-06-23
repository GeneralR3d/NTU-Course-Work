#Practical Exercise 2b
from sense_hat import SenseHat
sense = SenseHat()
sense.set_rotation(180)
sense.show_message("This is fun!")

red_str = input("Enter the value of the red color for message:")
green_str = input("Enter the value of the green color for message: ")
blue_str = input("Enter the value of the blue color for message: ")

msg_r_int = int(red_str)
msg_g_int = int(green_str)
msg_b_int = int(blue_str)
msg_color = (msg_r_int,msg_g_int, msg_b_int)
print(msg_color)

red_str=input ("Enter the value of the red color for background: ")
green_str=input ("Enter the value of the green color for background: ")
blue_str=input ("Enter the value of the blue color for background: ")

bg_r_int= int (red_str)
bg_g_int= int (green_str)
bg_b_int= int (blue_str)
bg_color= (bg_r_int, bg_g_int, bg_b_int)
print(bg_color)

speed_str = input("Enter the value of the display speed: ")
speed = float(speed_str)
print(speed)

sense.show_message ("I got it!", 
    text_colour=msg_color,
    back_colour=bg_color,
    scroll_speed = speed)