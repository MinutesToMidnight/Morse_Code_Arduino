/*
   Morse_Code_Arduino
   Turn your Arduino into a Morse Code blinking and beeping machine!
   __    __     __     __   __     __  __     ______   ______     ______
  /\ "-./  \   /\ \   /\ "-.\ \   /\ \/\ \   /\__  _\ /\  ___\   /\  ___\
  \ \ \-./\ \  \ \ \  \ \ \-.  \  \ \ \_\ \  \/_/\ \/ \ \  __\   \ \___  \
   \ \_\ \ \_\  \ \_\  \ \_\\"\_\  \ \_____\    \ \_\  \ \_____\  \/\_____\
    \/_/  \/_/   \/_/   \/_/ \/_/   \/_____/     \/_/   \/_____/   \/_____/
                               ______   ______
                              /\__  _\ /\  __ \
                              \/_/\ \/ \ \ \/\ \
                                 \ \_\  \ \_____\
                                  \/_/   \/_____/
   __    __     __     _____     __   __     __     ______     __  __     ______
  /\ "-./  \   /\ \   /\  __-.  /\ "-.\ \   /\ \   /\  ___\   /\ \_\ \   /\__  _\
  \ \ \-./\ \  \ \ \  \ \ \/\ \ \ \ \-.  \  \ \ \  \ \ \__ \  \ \  __ \  \/_/\ \/
   \ \_\ \ \_\  \ \_\  \ \____-  \ \_\\"\_\  \ \_\  \ \_____\  \ \_\ \_\    \ \_\
    \/_/  \/_/   \/_/   \/____/   \/_/ \/_/   \/_/   \/_____/   \/_/\/_/     \/_/

  MinutesToMidnight
  Now with more fun in every byte!

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#define LED_Pin         13
#define Speaker_Pin     10
const char Message[] PROGMEM = "hello i am beeping morse code"; //must be lower case

void setup()
{
        // put your setup code here, to run once:
        pinMode(LED_Pin, OUTPUT);
        pinMode(Speaker_Pin, OUTPUT);
        Serial.begin(9600);
}

void loop()
{
        // put your main code here, to run repeatedly:
        int letter = 0;
        Serial.println();

        while (Message[letter] != '\0')
        {
                Serial.print(Message[letter]);
                Morse_Lookup(Message[letter]);
                letter = letter + 1;
        }
}

void Dit()
{
        digitalWrite(LED_Pin, HIGH);
        tone(Speaker_Pin, 2600); // pin, frequency 30Hz-20KHz
        delay(50); //duration in mS
        noTone(Speaker_Pin);
        digitalWrite(LED_Pin, LOW);
        delay(100); //duration in mS
}

void Dah()
{
        digitalWrite(LED_Pin, HIGH);
        tone(Speaker_Pin, 2600); // pin, frequency 30Hz-20KHz
        delay(250); //duration in mS
        noTone(Speaker_Pin);
        digitalWrite(LED_Pin, LOW);
        delay(100); //duration in mS
}

void Morse_Lookup(char character)
{
        switch (character)
        {
        case 'a':
                Dit();
                Dah();
                break;
        case 'b':
                Dah();
                Dit();
                Dit();
                Dit();
                break;
        case 'c':
                Dah();
                Dit();
                Dah();
                Dit();
                break;
        case 'd':
                Dah();
                Dit();
                Dit();
                break;
        case 'e':
                Dit();
                break;
        case 'f':
                Dit();
                Dit();
                Dah();
                Dit();
                break;
        case 'g':
                Dah();
                Dah();
                Dit();
                break;
        case 'h':
                Dit();
                Dit();
                Dit();
                Dit();
                break;
        case 'i':
                Dit();
                Dit();
                break;
        case 'j':
                Dit();
                Dah();
                Dah();
                Dah();
                break;
        case 'k':
                Dah();
                Dit();
                Dah();
                break;
        case 'l':
                Dit();
                Dah();
                Dit();
                Dit();
                break;
        case 'm':
                Dah();
                Dah();
                break;
        case 'n':
                Dah();
                Dit();
                break;
        case 'o':
                Dah();
                Dah();
                Dah();
                break;
        case 'p':
                Dit();
                Dah();
                Dah();
                Dit();
                break;
        case 'q':
                Dah();
                Dah();
                Dit();
                Dah();
                break;
        case 'r':
                Dit();
                Dah();
                Dit();
                break;
        case 's':
                Dit();
                Dit();
                Dit();
                break;
        case 't':
                Dah();
                break;
        case 'u':
                Dit();
                Dit();
                Dah();
                break;
        case 'v':
                Dit();
                Dit();
                Dit();
                Dah();
                break;
        case 'w':
                Dit();
                Dah();
                Dah();
                break;
        case 'x':
                Dah();
                Dit();
                Dit();
                Dah();
                break;
        case 'y':
                Dah();
                Dit();
                Dah();
                Dah();
                break;
        case 'z':
                Dah();
                Dah();
                Dit();
                Dit();
                break;
        case ' ':
                delay(1500);
                break;
        default:
                digitalWrite(LED_Pin, LOW);
                noTone(Speaker_Pin);
                break;
        }
}
