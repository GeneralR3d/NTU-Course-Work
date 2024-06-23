from sense_hat import SenseHat
import colorzero

sense = SenseHat()

sense.set_rotation(90)
sense.show_message("Welcome to Cx1003! now is Sc1003 la",scroll_speed = 0.03)
sense.show_message("Type in stuff into the keyboard now")

userBackColour = input("Enter the back colour you want")
userTextColour = input("Enter the text colour you want")
userScrollSpeed = int(input("Enter scroll speed, the lower the faster"))

displaybackColour = colorzero.Color(userBackColour)
RGBBackcolour = displaybackColour.rgb_bytes

displaytextColour = Color(userTextColour)
RGBTextcolour = displaytextColour.rgb_bytes

sense.show_message("You are duck",back_colour =RGBBackcolour,text_colour=RGBTextcolour,scroll_speed = userScrollSpeed)
print("hello it runs!")
