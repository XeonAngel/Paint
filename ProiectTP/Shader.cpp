#include "Square.h"
using namespace std;

GLuint CreateShader	    (const string&, GLenum);
string LoadShader	    (const string&		   );
void   CheckShaderError (GLuint		  , GLuint, bool, const string& );


Shader::Shader(){
}


Shader::Shader(const std::string& fileName, int newType){
	initShader(fileName, newType);
}


void Shader::initShader(const std::string& fileName, int newType){


	program   = glCreateProgram();
	vShader   = CreateShader( LoadShader(fileName + ".vertshader") , GL_VERTEX_SHADER);		//Crearea Vertex Shader-ului
	fShader   = CreateShader( LoadShader(fileName + ".fragshader") , GL_FRAGMENT_SHADER);   //Crearea Fragment Shader-ului
	
	
	//Legarea Shader-urilor
	glAttachShader( program, vShader );		
	glAttachShader( program, fShader );	



	glBindAttribLocation(program, 0, "position");			

	 
	glLinkProgram( program );								


	CheckShaderError( program, GL_LINK_STATUS, true, "ERROR");
	glValidateProgram( program );							
	CheckShaderError( program, GL_VALIDATE_STATUS, true, "ERROR");

	
	//Setam Shader-ul sa ii poata fi shimbata culoara pe care o foloseste

	uniforms[TRANSFORM_U] = glGetUniformLocation(program, "transform");
	uniforms[ CHANGE_COLOR_U ] = glGetUniformLocation(program, "new_color");
			
	//Declaram programul folosit
	glUseProgram(program);
}


GLuint CreateShader(const string& ShaderCode, GLenum ShaderType){
	GLuint shader = glCreateShader(ShaderType);				

	if(shader == NULL) std::cerr << "ERROR SHADER";

	const GLchar* Source;
	GLint SourceLen;

	Source	  = ShaderCode.c_str();							

	SourceLen = ShaderCode.length();

	//Compiarea Shader-ului
	glShaderSource(shader, 1, &Source, &SourceLen);			
	glCompileShader(shader);

	return shader;
}






string LoadShader(const string& fileName)
{

    ifstream file;	
    file.open((fileName).c_str());

    string output;
    string line;

    if(file.is_open()){
        while(file.good()){
            getline(file, line);
			output.append(line + "\n");
        }
    }
    else{
		cerr << "Unable to load shader: " << fileName;
    }

    return output;
}

void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const string& errorMessage)
{
    GLint  success = 0;
    GLchar error[1024] = { 0 };

    isProgram ?	glGetProgramiv(shader, flag, &success) : glGetShaderiv(shader, flag, &success);

    if(success == GL_FALSE){
       isProgram ? glGetProgramInfoLog(shader, sizeof(error), NULL, error)
				 : glGetShaderInfoLog (shader, sizeof(error), NULL, error);
        cerr << errorMessage << ": '" << error << "'";
    }
}




void Shader::Update(vec4 Color, Transform translation){
	glUseProgram(program);	

	mat4 m = translation.Translation_Matrix();
	glUniformMatrix4fv(uniforms[TRANSFORM_U], 1, GL_FALSE, &m[0][0]);
	glUniform4f(uniforms[CHANGE_COLOR_U], Color.x, Color.y, Color.z, Color.w);
}


Shader::~Shader(){
	glDetachShader(program, vShader);
	glDetachShader(program, fShader);
	
	glDeleteShader( vShader);
	glDeleteShader( fShader);
	
	glDeleteProgram(program);
}