import sense_hat, time, random


r=(255,0,0)
w=(255,255,255)
b=(0,0,0)
g=(0,255,0)
bl=(0,0,255)

board2D = [
          [r,r,r,r,r,r,r,r],
          [r,b,b,b,b,b,b,r],
          [r,r,r,b,b,b,b,b],
          [r,b,b,b,b,b,b,r],
          [r,b,r,b,b,b,b,r],
          [b,b,b,b,b,r,b,r],
          [b,b,b,b,b,b,b,b],
          [r,r,b,r,r,b,r,r]
          
        ]

def main():
    display = sense_hat.SenseHat()
    

    marble = (2,2)
    target = (4,4)
    game_over = False
    
    row,col = marble
    board2D[row][col] = w
    i,j = target
    board2D[i][j] = g
    wall_generator(board2D)
    
    
    board1D = sum(board2D,[])
    display.set_pixels(board1D)
    time.sleep(0.05)
    
    while not game_over:
        pitch = display.get_orientation()['pitch']
        roll = display.get_orientation()['roll']
        
        board2D[row][col] = b
        row,col = move_marble(pitch,roll,row,col)
        board2D[row][col] = w
        
        if row == i and col == j:
            game_over = True
        
        
        board1D = sum(board2D,[])
        display.set_pixels(board1D)
        time.sleep(0.05)
    
    else:
        display.show_message("yayyyy!!")
        
    
    
    
    
def move_marble(pitch,roll,row,col):
    
    #rotate horizontal direction
    #left = col -1
    #right = col +1
    #up = row -1
    #down = row +1
    new_row = row
    new_col = col
    if 10 < pitch < 80 and col != 0:
        new_col -= 1
    elif 290 < pitch < 350 and col != 7:
        new_col += 1
     
    if 290 < roll < 350 and row != 0:
        new_row -= 1
    elif 10 < roll < 80 and row != 7:
        new_row += 1
    
    new_row,new_col = check_wall(row,col,new_row,new_col)
    return new_row,new_col


def check_wall(row,col,new_row,new_col):
    
    global board2D
    
    if board2D[new_row][new_col] != r:
        return new_row,new_col
    elif board2D[new_row][col] !=  r:
        return new_row,col
    elif board2D[row][new_col] != r:
        return row,new_col
    else:
        return row,col
    
def wall_generator(board):
    
    red_credits = 0
    for i, row in enumerate(board):
        for j, pixel in enumerate(row):
            if pixel == r:
                board[i][j] = b
                red_credits+=1
                print("hello")
                
    while red_credits > 0:
        for row in board:
            for pixel in row:
                if pixel != w and pixel != g:
                    if random.choice((0,1)) == 0:
                        pixel = r
                        red_credits -= 1
                    
    return board
    
    

if __name__ == "__main__":
    main()
    