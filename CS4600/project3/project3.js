// [TO-DO] Complete the implementation of the following class and the vertex shader below.

class CurveDrawer {
	constructor()
	{
		this.prog   = InitShaderProgram( curvesVS, curvesFS );
		
		// [TO-DO] Other initializations should be done here.
		this.mvp=gl.getUniformLocation(this.prog,'mvp');
		
		// [TO-DO] This is a good place to get the locations of attributes and uniform variables.
		this.vertPos=gl.getAttribLocation(this.prog,'t');
		
		//Get the locations for p0, p1, p2, p3.
		this.cp=[];
		for(let i=0;i<4;i++){
			this.cp.push(gl.getUniformLocation(this.prog,`p${i}`));
		} 

		// Initialize the attribute buffer
		this.buffer=gl.createBuffer();
		
		this.steps = 100;
		var tv = [];
		for ( var i=0; i<this.steps; ++i ) {
			tv.push( i / (this.steps-1) );
		}
		
		// [TO-DO] This is where you can create and set the contents of the vertex buffer object
		// for the vertex attribute we need.
		gl.bindBuffer(gl.ARRAY_BUFFER,this.buffer);
		gl.bufferData(gl.ARRAY_BUFFER,new Float32Array(tv),gl.STATIC_DRAW);
	}
	setViewport( width, height )
	{
		// [TO-DO] This is where we should set the transformation matrix.
		var transM=[2/width,0,0,0,0,-2/height,0,0,0,0,1,0,-1,1,0,1];
		
		// [TO-DO] Do not forget to bind the program before you set a uniform variable value.
		gl.useProgram( this.prog );	// Bind the program
		
		gl.uniformMatrix4fv(this.mvp,false,transM);
	}
	updatePoints( pt )
	{
		// [TO-DO] The control points have changed, we must update corresponding uniform variables.
		// [TO-DO] Do not forget to bind the program before you set a uniform variable value.
		// [TO-DO] We can access the x and y coordinates of the i^th control points using
		var x;
		var y;
		gl.useProgram(this.prog);
		for(let i=0;i<4;i++)
		{
			x=pt[i].getAttribute("cx");
			y=pt[i].getAttribute("cy");
			gl.uniform2fv(this.cp[i],new Float32Array([x,y]));
		}
	}
	draw()
	{
		// [TO-DO] This is where we give the command to draw the curve.
		// [TO-DO] Do not forget to bind the program and set the vertex attribute.

		gl.useProgram(this.prog);
		gl.bindBuffer(gl.ARRAY_BUFFER,this.buffer); 
		gl.vertexAttribPointer(this.vertPos,2,gl.FLOAT,false,0,0);
		gl.enableVertexAttribArray(this.vertPos);
		gl.drawArrays (gl.LINE_STRIP,0,this.steps/2);
	}
}

// Vertex Shader
var curvesVS = `
	attribute float t;
	uniform mat4 mvp;
	uniform vec2 p0;
	uniform vec2 p1;
	uniform vec2 p2;
	uniform vec2 p3;
	void main()
	{
		// [TO-DO] Replace the following with the proper vertex shader code
		float inv=1.0-t;
		float inv2=inv*inv;
		float t2=t*t;

		//Computing the Bezier curve point.
		vec2 pos = p0*inv*inv2+p1*3.0*t*inv2+p2*3.0*inv*t2+p3*t2*t;

		//update gl position
		gl_Position = mvp * vec4(pos,0,1);
	}
`;

// Fragment Shader
var curvesFS = `
	precision mediump float;
	void main()
	{
		gl_FragColor = vec4(1,0,0,1);
	}
`;