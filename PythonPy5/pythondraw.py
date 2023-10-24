import py5
def setup():
	py5.size(400, 400)

def draw():
	py5.background(255)
	py5.fill(255,0,0)
	py5.ellipse(200, 200, 50, 50)
	
py5.run_sketch()
