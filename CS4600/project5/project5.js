// This function takes the translation and two rotation angles (in radians) as input arguments.
// The two rotations are applied around x and y axes.
// It returns the combined 4x4 transformation matrix as an array in column-major order.
// You can use the MatrixMult function defined in project5.html to multiply two 4x4 matrices in the same format.
function GetModelViewMatrix( translationX, translationY, translationZ, rotationX, rotationY )
{
	// [TO-DO] Modify the code below to form the transformation matrix.

	//x rotation matrix
	var rotXMat= 
	[
		1,0,0,0,
		0,Math.cos(rotationX),-Math.sin(rotationX),0,
		0,Math.sin(rotationX),Math.cos(rotationX),0,
		0,0,0,1
	];

	//y rotation matrix
	var rotYMat= 
	[
		Math.cos(rotationY),0,Math.sin(rotationY),0,
		0,1,0,0,
		-Math.sin(rotationY),0,Math.cos(rotationY),0,
		0,0,0,1
	];

	//multiplying both rotation matrices
	var rotMatrix = MatrixMult(rotXMat,rotYMat);
	
	var trans = [
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		translationX, translationY, translationZ, 1
	];

	//apply rotation matrix to transformation matrix
	var mv = MatrixMult(trans,rotMatrix);
	return mv;
}


// [TO-DO] Complete the implementation of the following class.

class MeshDrawer
{
	// The constructor is a good place for taking care of the necessary initializations.
	constructor()
	{
		// [TO-DO] initializations
		this.prog = InitShader(modelVS, modelFS);
		gl.useProgram(this.prog);
		this.mvp=gl.getUniformLocation(this.prog,'mvp');
		this.sampler=gl.getUniformLocation(this.prog,'tex');
		this.lightDir=gl.getUniformLocation(this.prog,'lightDir');
		this.mv=gl.getUniformLocation(this.prog,'mv');
		this.normMat=gl.getUniformLocation(this.prog,'normMat');
		this.shine=gl.getUniformLocation(this.prog,'shine');
		this.swap=gl.getUniformLocation(this.prog,'swap');
		this.vertPos=gl.getAttribLocation(this.prog,'pos');
		this.textureCoord=gl.getAttribLocation(this.prog,'txc');
		this.normals=gl.getAttribLocation(this.prog,'norm');
	}
	
	// This method is called every time the user opens an OBJ file.
	// The arguments of this function is an array of 3D vertex positions,
	// an array of 2D texture coordinates, and an array of vertex normals.
	// Every item in these arrays is a floating point value, representing one
	// coordinate of the vertex position or texture coordinate.
	// Every three consecutive elements in the vertPos array forms one vertex
	// position and every three consecutive vertex positions form a triangle.
	// Similarly, every two consecutive elements in the texCoords array
	// form the texture coordinate of a vertex and every three consecutive 
	// elements in the normals array form a vertex normal.
	// Note that this method can be called multiple times.
	setMesh( vertPos, texCoords, normals )
	{
		// [TO-DO] Update the contents of the vertex buffer objects.
		gl.useProgram(this.prog);

		this.vertbuffer=gl.createBuffer();
		gl.bindBuffer(gl.ARRAY_BUFFER,this.vertbuffer);
		gl.bufferData(gl.ARRAY_BUFFER,new Float32Array(vertPos),gl.STATIC_DRAW);

		this.texBuffer=gl.createBuffer();
		gl.bindBuffer(gl.ARRAY_BUFFER,this.texBuffer);
		gl.bufferData(gl.ARRAY_BUFFER,new Float32Array(texCoords),gl.STATIC_DRAW);

		this.normBuffer=gl.createBuffer();
		gl.bindBuffer(gl.ARRAY_BUFFER,this.normBuffer);
		gl.bufferData(gl.ARRAY_BUFFER,new Float32Array(normals),gl.STATIC_DRAW);

		this.numTriangles = vertPos.length / 3;
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
	// The arguments are the model-view-projection transformation matrixMVP,
	// the model-view transformation matrixMV, the same matrix returned
	// by the GetModelViewProjection function above, and the normal
	// transformation matrix, which is the inverse-transpose of matrixMV.
	draw( matrixMVP, matrixMV, matrixNormal )
	{
		// [TO-DO] Complete the WebGL initializations before drawing
		gl.useProgram(this.prog);

		gl.uniformMatrix4fv(this.mvp,false,matrixMVP);
		gl.uniformMatrix4fv(this.mv,false,matrixMV);
		gl.uniformMatrix3fv(this.normMat,false,matrixNormal);

		gl.bindBuffer(gl.ARRAY_BUFFER,this.vertbuffer);
		gl.vertexAttribPointer(this.vertPos,3,gl.FLOAT,false,0,0);
		gl.enableVertexAttribArray(this.vertPos);

		gl.bindBuffer(gl.ARRAY_BUFFER,this.texBuffer);
		gl.vertexAttribPointer(this.textureCoord,2,gl.FLOAT,false,0,0);
		gl.enableVertexAttribArray(this.textureCoord);

		gl.bindBuffer(gl.ARRAY_BUFFER,this.normBuffer);
		gl.vertexAttribPointer(this.normals,3,gl.FLOAT,false,0,0);
		gl.enableVertexAttribArray(this.normals);

		gl.drawArrays(gl.TRIANGLES,0,this.numTriangles);
	}
	
	// This method is called to set the texture of the mesh.
	// The argument is an HTML IMG element containing the texture data.
	setTexture( img )
	{
		// [TO-DO] Bind the texture

		gl.useProgram(this.prog);
		this.tex=gl.createTexture();
		gl.bindTexture(gl.TEXTURE_2D,this.tex);
		
		// You can set the texture image data using the following command.
		gl.texImage2D( gl.TEXTURE_2D, 0, gl.RGB, gl.RGB, gl.UNSIGNED_BYTE, img );

		// [TO-DO] Now that we have a texture, it might be a good idea to set
		// some uniform parameter(s) of the fragment shader, so that it uses the texture.

		gl.generateMipmap(gl.TEXTURE_2D);
		gl.texParameteri(gl.TEXTURE_2D,gl.TEXTURE_MIN_FILTER,gl.LINEAR_MIPMAP_LINEAR);
		gl.texParameteri(gl.TEXTURE_2D,gl.TEXTURE_WRAP_S,gl.REPEAT);
		gl.texParameteri(gl.TEXTURE_2D,gl.TEXTURE_WRAP_T,gl.REPEAT);
		gl.activeTexture(gl.TEXTURE0);
		gl.bindTexture(gl.TEXTURE_2D,this.tex);
		gl.uniform1i(this.sampler,0);
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
				gl.uniform1i(this.sampler,1);
			}
			else
			{
				gl.uniform1i(this.sampler,0);
			}
		}
		else
		{
			gl.uniform1i(this.sampler,1);
		}

	}
	
	// This method is called to set the incoming light direction
	setLightDir( x, y, z )
	{
		// [TO-DO] set the uniform parameter(s) of the fragment shader to specify the light direction.
		gl.useProgram(this.prog);
		gl.uniform3f(this.lightDir,x,y,z);
	}
	
	// This method is called to set the shininess of the material
	setShininess( shininess )
	{
		// [TO-DO] set the uniform parameter(s) of the fragment shader to specify the shininess.
		gl.useProgram(this.prog);
		gl.uniform1f(this.shine,shininess);
	}
}

function InitShader(vsSource, fsSource) 
{
	const vs=CompileShader(gl.VERTEX_SHADER,vsSource);
	const fs=CompileShader(gl.FRAGMENT_SHADER,fsSource);
	const program=gl.createProgram();
	
	gl.attachShader(program,vs);
	gl.attachShader(program,fs);
	gl.linkProgram(program);

	if (!gl.getProgramParameter(program,gl.LINK_STATUS)) 
	{
		alert('Unable to initialize the shader program: '+gl.getProgramInfoLog(program));
		return null;
	}
	
	return program;
}

// Vertex shader source code
var modelVS = 
`
	attribute vec3 pos;
	attribute vec3 norm;
	attribute vec2 txc;
	uniform mat4 mvp;
	uniform mat4 mv;
	uniform mat3 normMat;
	uniform vec3 lightDir;	
	varying vec2 texCoord;	
	varying vec3 normal;
	varying vec3 position;
	uniform int swap;
	void main()
	{
		vec3 swapVec;
		if(swap==1)
		{
			swapVec.xyz=vec3(pos.x,pos.z,pos.y);
		}
		else
		{
			swapVec.xyz=vec3(pos.x,pos.y,pos.z);
		}
		gl_Position=mvp*vec4(swapVec,1);
		texCoord=txc;
		normal=norm;
		position=pos;
	}
`;
// Fragment shader source code
var modelFS = 
`
	precision mediump float;
	uniform sampler2D tex;
	uniform float shine;
	uniform mat3 normMat;
	uniform vec3 lightDir;	
	varying vec2 texCoord;
	varying vec3 normal;
	varying vec3 position;
	void main()
	{
		vec3 lightCol=vec3(1,1,1);
		vec4 Kd=texture2D(tex,texCoord);
		vec4 Ks=vec4(1,1,1,1);

		vec3 transformedNormal=normMat*normal;
		float cosTheta=dot(transformedNormal,lightDir);		
		vec3 h=normalize(lightDir-position);
		float cosPhi=dot(transformedNormal,h);
		
		vec4 lhs=cosTheta*Kd;
		vec4 rhs=Ks*pow(cosPhi,shine);
		gl_FragColor=lhs+rhs;
	}
`;
