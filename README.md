## A program that applies filters to BMPs.<br/>

The four filters implemented are Grayscale (-g), Reflection (-r) and Blur (-b).<br/>

The following commands can be used to generate different filtered images.<br/>


```$ ./filter -g INFILE.bmp OUTFILE.bmp``` <br/>
```$ ./filter -r INFILE.bmp OUTFILE.bmp``` <br/>
```$ ./filter -b INFILE.bmp OUTFILE.bmp``` <br/>

```INFILE.bmp``` is the name of the input image and ```OUTFILE.bmp``` is the name of the resulting image after a filter has been applied.<br/>

## Example: <br/>
Sample input: <br/>
![original tower image](https://github.com/arpitmeher/filter-CS50x-2021/blob/main/images/tower.bmp)

Output of Grayscale Filter:<br/>
![Grayscale](https://github.com/arpitmeher/filter-CS50x-2021/blob/main/tower_g.bmp)

Output of reflection Filter:<br/>
![reflection](https://github.com/arpitmeher/filter-CS50x-2021/blob/main/tower_r.bmp)

Output of blur Filter:<br/>
![blurred](https://github.com/arpitmeher/filter-CS50x-2021/blob/main/tower_b.bmp)
