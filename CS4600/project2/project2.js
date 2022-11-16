// Returns a 3x3 transformation matrix as an array of 9 values in column-major order.
// The transformation first applies scale, then rotation, and finally translation.
// The given rotation value is in degrees.
function GetTransform( positionX, positionY, rotation, scale )
{
	//convert degrees to radian then calculate cos and sin
	let radians=(rotation*Math.PI)/180;
	let cosT=Math.cos(radians);
	let sinT=Math.sin(radians);

	//new scale matrix
	let scaleM=[scale,0,0,0,scale,0,0,0,1];
	//new rotation matrix
	let rotationM=[cosT,sinT,0,-sinT,cosT,0,0,0,1];
	//new translation matrix
	let translationM=[1,0,0,0,1,0,positionX,positionY,1];

	//apply the transformation
	let newTransformation=ApplyTransform(ApplyTransform(scaleM,rotationM),translationM);
		
	return newTransformation;
}

// Returns a 3x3 transformation matrix as an array of 9 values in column-major order.
// The arguments are transformation matrices in the same format.
// The returned transformation first applies trans1 and then trans2.
function ApplyTransform( trans1, trans2 )
{
	//initial matrix
	let ret = [0, 0, 0, 0, 0, 0, 0, 0, 0];

	//3x3 matrix multiplication.
	for (let i=0; i<3; i++) 
	{
		for (let j=0; j<3; j++) 
		{
			for (let k=0; k<3; k++) 
			{
				ret[i*3+j] += trans1[i*3+k]*trans2[j+k*3];
			}
		}
	}
	
	return ret;
}
