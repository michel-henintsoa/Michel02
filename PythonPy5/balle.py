import py5

pos_x=50
i=5
def setup():
    py5.size(480, 120)

def draw():
    global pos_x
    global i
    py5.background(255)
    py5.fill(10)
    py5.ellipse(pos_x, 60, 50, 50)
    if pos_x==480 or pos_x==0: i=-i
    pos_x+=i

py5.run_sketch()