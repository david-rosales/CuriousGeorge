import math
# takes the sensed distance to the tennis ball and location on the coordinate system overlaid over the camera frame
# (0,0) is the top left, increasing down and to the right
# width = 640, height = 480 
def track_ball(distance, radius, x, y):
    WIDTH = 640
    HEIGHT = 480
    HORIZON = HEIGHT/2

    TENNIS_BALL_ACTUAL = 5

    # Move forward until wihtin GRAB_DISTANCE
    GRAB_DISTANCE = 0.5

    # grab if the circle is near this point
    GRAB_Y = 240 
    GRAB_X =  320

    # center correction
    center_delta = GRAB_X - x 

    # use pixel radius of detected ball and known radius of tennis ball to get scale for horizontal distance
    pixel_to_dist = TENNIS_BALL_ACTUAL / radius 
    horizontal_distance = pixel_to_dist * center_delta

    # distance correction
    distance_delta = distance - GRAB_DISTANCE
    
    MAX_SPEED = 10
    MAX_TURN = 10
    DIST_DELTA_THRESHOLD = 0
    CENTER_DELTA_THRESHOLD = math.pi/3

    commands = []

    if distance_delta > DIST_DELTA_THRESHOLD:
        commands.append("forward") #move:+str(round(distance_delta, 2))
   
    print("distance: ", distance)
    print("horizontal_distance: ", horizontal_distance)
    # turn gives angle going CCW from x-axis
    turn = math.atan2(distance, -horizontal_distance)

    #convert to angle going CW from y-axis (makes sense from George's perspective)
    turn = -turn + math.pi/2


    if abs(turn) > CENTER_DELTA_THRESHOLD:
        commands.append("turn") #+str(round(turn, 2))

    # check if we are close enough to grab
    if len(commands) == 0:
        return ['grab']
    else:
        return commands
     

    
