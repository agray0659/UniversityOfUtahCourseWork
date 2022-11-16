// This function takes the projection matrix, the translation, and two rotation angles (in radians) as input arguments.
// The two rotations are applied around x and y axes.
// It returns the combined 4x4 transformation matrix as an array in column-major order.
// The given projection matrix is also a 4x4 matrix stored as an array in column-major order.
// You can use the MatrixMult function defined in project4.html to multiply two 4x4 matrices in the same format.
function GetModelViewProjection( projectionMatrix, translationX, translationY, translationZ, rotationX, rotationY )
{
	// [TO-DO] Modify the code below to form the transformation matrix.

	let rX = rotationX
	let rY = rotationY
	
	var trans = [
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		translationX, translationY, translationZ, 1
	];
	var rotationMat_X=
	[
		1,0,0,0,
		0,cos(rX),sin(rX),0,
		0,-sin(rX),cos(rX),0,
		0,0,0,1
	];
	var rotationMat_Y=
	[
		cos(rY),0,-sin(rY),0,
		0,1,0,0,
		sin(rY),0,cos(rY),0,
		0,0,0,1
	];
	var newMat=MatrixMult(trans,MatrixMult(rotationMat_X,rotationMat_Y))
	var mvp = MatrixMult( projectionMatrix, newMat );
	return mvp;
}

// [TO-DO] Complete the implementation of the following class.

class MeshDrawer
{
	// The constructor is a good place for taking care of the necessary initializations.
	constructor()
	{
		// [TO-DO] initializations
		this.prog=InitShaderProgram(objVS,objFS);
		this.mvp=gl.getUniformLocation(this.prog,'mvp');
		this.vertPos=gl.getAttribLocation(this.prog,'pos');
		this.vertbuffer=gl.createBuffer();
		this.textureBuffer=gl.createBuffer();
		this.loaded=gl.getUniformLocation(this.prog,'loaded');
		this.swap=gl.getUniformLocation(this.prog,'swap');
		this.flag=gl.getAttribLocation(this.prog,'flag');
		this.toShow=gl.getUniformLocation(this.prog,'toShow');
		this.sampler=gl.getUniformLocation(this.prog,'tex');
		this.txc=gl.getAttribLocation(this.prog,'txc');
		this.loaded=false;
	}
	
	// This method is called every time the user opens an OBJ file.
	// The arguments of this function is an array of 3D vertex positions
	// and an array of 2D texture coordinates.
	// Every item in these arrays is a floating point value, representing one
	// coordinate of the vertex position or texture coordinate.
	// Every three consecutive elements in the vertPos array forms one vertex
	// position and every three consecutive vertex positions form a triangle.
	// Similarly, every two consecutive elements in the texCoords array
	// form the texture coordinate of a vertex.
	// Note that this method can be called multiple times.
	setMesh( vertPos, texCoords )
	{
		// [TO-DO] Update the contents of the vertex buffer objects.
		this.numTriangles = vertPos.length / 3;
		gl.bindBuffer(gl.ARRAY_BUFFER,this.vertbuffer);
		gl.bufferData(gl.ARRAY_BUFFER,new Float32Array(vertPos),gl.STATIC_DRAW);
		gl.bindBuffer(gl.ARRAY_BUFFER,this.textureBuffer);
		gl.bufferData(gl.ARRAY_BUFFER,new Float32Array(texCoords),gl.STATIC_DRAW);
	}
	
	// This method is called when the user changes the state of the
	// "Swap Y-Z Axes" checkbox. 
	// The argument is a boolean that indicates if the checkbox is checked.
	swapYZ( swap )
	{
		// [TO-DO] Set the uniform parameter(s) of the vertex shader
		gl.useProgram(this.prog);
		console.log(this.swap)
		if(swap)
		{
			gl.uniform1i(this.swap,1);
		}
		else
		{
			gl.uniform1i(this.swap,0);
		}
	}
	
	// This method is called to draw the triangular mesh.
	// The argument is the transformation matrix, the same matrix returned
	// by the GetModelViewProjection function above.
	draw( trans )
	{
		// [TO-DO] Complete the WebGL initializations before drawing
		gl.useProgram(this.prog);
		gl.uniformMatrix4fv(this.mvp,false,trans);
		gl.bindBuffer(gl.ARRAY_BUFFER,this.vertbuffer);
		
		gl.vertexAttribPointer(this.vertPos,3,gl.FLOAT,false,0,0);
		gl.enableVertexAttribArray(this.vertPos);
		gl.bindBuffer(gl.ARRAY_BUFFER,this.textureBuffer);
		
		gl.vertexAttribPointer(this.txc,2,gl.FLOAT,false,0,0);
		gl.enableVertexAttribArray(this.txc);
		gl.drawArrays( gl.TRIANGLES, 0, this.numTriangles );
	}
	
	// This method is called to set the texture of the mesh.
	// The argument is an HTML IMG element containing the texture data.
	setTexture( img )
	{
		// [TO-DO] Bind the texture
		const mytex=gl.createTexture();
		gl.bindTexture(gl.TEXTURE_2D,mytex);
		
		// You can set the texture image data using the following command.
		gl.texImage2D(gl.TEXTURE_2D,0,gl.RGB,gl.RGB,gl.UNSIGNED_BYTE,img);
		gl.generateMipmap(gl.TEXTURE_2D);
		gl.texParameteri(gl.TEXTURE_2D,gl.TEXTURE_MIN_FILTER,gl.LINEAR_MIPMAP_LINEAR);

		// [TO-DO] Now that we have a texture, it might be a good idea to set
		// some uniform parameter(s) of the fragment shader, so that it uses the texture.
		gl.useProgram(this.prog)
		gl.uniform1i(this.sampler,0)
		this.loaded=true;
		gl.useProgram(this.prog);
		gl.uniform1i(this.toShow,1);
	}
	
	// This method is called when the user changes the state of the
	// "Show Texture" checkbox. 
	// The argument is a boolean that indicates if the checkbox is checked.
	showTexture( show )
	{
		// [TO-DO] set the uniform parameter(s) of the fragment shader to specify if it should use the texture.
		gl.useProgram(this.prog);
		if(show)
		{
			if(this.loaded===true)
			{
				gl.uniform1i(this.toShow,1);
			}
			else
			{
				gl.uniform1i(this.toShow,0);
			}
		}
		else
		{
			gl.uniform1i(this.toShow,0);
		}
	}
	
}

//helper function
let sin = Math.sin;
let cos = Math.cos;

function getDegree(num)
{
	return (num*(Math.PI/180))
}

// Vertex shader code
var objVS = `
	attribute vec3 pos;
	uniform mat4 mvp;
	uniform int swap;
	uniform bool loaded;
	varying vec2 texCoord;
	attribute vec2 txc;
	
	void main()
	{
		vec3 someVec;
		if(swap==1)
		{
			someVec.xyz=vec3(pos.x,pos.z,pos.y);
		}
		else
		{
			someVec.xyz=vec3(pos.x,pos.y,pos.z);
		}
		texCoord=txc;
		gl_Position=mvp*vec4(someVec,1);
	}
`;
// Fragment shader code
var objFS = `
	precision mediump float;
	uniform bool toShow;
	uniform sampler2D tex;
	varying vec2 texCoord;
	
	void main()
	{
		if(toShow)
		{
			gl_FragColor=texture2D(tex,texCoord);		
		}
		else
		{
			gl_FragColor=vec4(1,gl_FragCoord.z*gl_FragCoord.z,0,1);
		}
	}
`;