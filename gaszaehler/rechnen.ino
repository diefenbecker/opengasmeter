void looprechnen() {

  if (cfg.data_impulsgeber==0) {
    verbrauch=(startwert+(value*10)); //0.1 pro qm
  } else {
    verbrauch=(startwert+value); //0.01 pro qm
  }
  verbrauch_kwh=verbrauch*cfg.data_brennwert/100*cfg.data_zustandszahl/100;

  //Impuls in Speicher schreiben
  Serial.println(cfg.data_impulszaehler);
  cfg.data_impulszaehler=cfg.data_impulszaehler+1;
  Serial.println(cfg.data_impulszaehler);
  speicherekonfig();  
}
  