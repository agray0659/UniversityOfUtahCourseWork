// bgImg is the background image to be modified.
// fgImg is the foreground image.
// fgOpac is the opacity of the foreground image.
// fgPos is the position of the foreground image in pixels. It can be negative and (0,0) means the top-left pixels of the foreground and background are aligned.
function composite( bgImg, fgImg, fgOpac, fgPos )
{
    //values to account for and changes to the position of image
    offsetX = fgPos.x*4;
    offsetY = fgPos.y*4;
    
    //iterate every 4 value to next pixel  
    for(let row = 0; row < fgImg.height*4; row += 4) 
    {
        for (let col = 0;col < fgImg.width*4;col += 4)
        {
            //background index
            bgI = (col+offsetX) + bgImg.width * (row+offsetY);
            //foreground index
            fgI = col + fgImg.width * row;
            
            //if the alpha value of either the background or the foreground is not 0, then proceed to calculate the new color value
            if(bgImg.data[bgI + 3] != 0 && fgImg.data[fgI + 3] != 0)
            {
                //original background color values
                bgR=bgImg.data[bgI];
                bgG=bgImg.data[bgI+1];
                bgB=bgImg.data[bgI+2];
                
                //foreground color values
                fgR=fgImg.data[fgI];
                fgG=fgImg.data[fgI+1];
                fgB=fgImg.data[fgI+2];

                //foreground alpha value with opacity
                fgAlpha = (fgImg.data[fgI+3] / 255 ) * fgOpac;

                //new calculated values replace original background color values
                bgImg.data[bgI]=(bgR * (1 - fgAlpha)  + fgR * fgAlpha );
                bgImg.data[bgI+1]=(bgG * (1 - fgAlpha)  + fgG * fgAlpha );                 
                bgImg.data[bgI+2]=(bgB * (1 - fgAlpha)  + fgB * fgAlpha );
            }
        } 
    }
}
