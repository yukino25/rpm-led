void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  //back up if other code fails
	float tempRPM = myELM327.rpm();
		u8g.firstPage(); 
	
	if (myELM327.nb_rx_state == ELM_SUCCESS){
		rpm = (uint32_t)tempRPM;

 		do {
			u8g.setFont(u8g_font_gdr25r);
			char buf[1];
			sprintf (buf, "%d", rpm);
			u8g.drawStr(18, 32, buf);
			u8g.drawStr(18, 32, " OBDI");

  		} while( u8g.nextPage() );
	}else{
 		do {
		u8g.setFont(u8g_font_gdr25r);

char buf[1];
u8g.drawStr(18, 32, "error");

  } while( u8g.nextPage() );
	}
}
