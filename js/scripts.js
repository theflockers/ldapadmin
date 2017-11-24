function GetBrowser() {

	browsername=navigator.appName;
	if (browsername.indexOf("Netscape")!=-1)
		 {browsername="NS"}
	else
		{if (browsername.indexOf("Microsoft")!=-1) {browsername="MSIE"}
	else {browsername="N/A"}};
	
	return browsername;
}

/* Funcões 90% Cosméticas!*/

/* Deixa item do menu com aspecto de Selecionado */
function selectItem(oid) {
	
	var menu = new Array;
	
	menu[0] = "usrdom";
	menu[1] = "aliasmenu";
	
	/* Verifica se o elemento existe antes de colocá-lo dentro do array*/
	for(x=2;x<20;x++) {
		if(document.getElementById(x)) {
				menu[menu.length]=x;
		}			
	}

	/* Remove seleção do ultimo item */

	for(i=0;i<menu.length;i++) {
		document.getElementById(menu[i]).style.backgroundColor='#fff';
		document.getElementById(menu[i]).style.border='none';
	}
  /* Seleciona item corrente */
	document.getElementById(oid).style.backgroundColor='#eee';
	document.getElementById(oid).style.borderStyle='dotted';
	document.getElementById(oid).style.borderWidth='1px';		
}

/* Exibe o menu esquerdo chamado pela função rightmenu() */
function showmenu(item) {
	
	obj=document.getElementById(item).style.visibility;
	
	if(obj=='hidden') 
		document.getElementById(item).style.visibility='visible';
	else
		document.getElementById(item).style.visibility='hidden';
}

/* Exibe o menu esquerdo chamado pela função rightmenu(). 
     Esta função exibe o menu na coordenada informada */     
function showmenu2(item,X,Y) {
	
	objeto=document.getElementById(item);
 
	if(GetBrowser()=="NS") {
		objeto.style.top=Y+'px';
		objeto.style.left=X+'px';
	}else{
		objeto.style.top=(Y-140)+'px';
		objeto.style.left=(X-20)+'px';
	}
   		
	if(objeto.style.visibility=='hidden') 
		objeto.style.visibility='visible';
	else
		objeto.style.visibility='hidden';
	
}

/* Função para Mostrar menu de navegação */
function show(item) {


	if(GetBrowser()=="NS") {
	
		obj=document.getElementById(item).style.visibility;
	
		/*Caso o objeto estive escondido, mostra-o */ 
		if(obj=='collapse') 
			document.getElementById(item).style.visibility='visible';
		else
			document.getElementById(item).style.visibility='collapse';
	}else {
		obj=document.getElementById(item).style.display;

		if(obj=='none') 
			document.getElementById(item).style.display='inline';
		else
			document.getElementById(item).style.display='none';
	}
	
	
}

/* Função para menu direito */
function rightmenu(event,elemento,oid) {
 
   var X;  /* Variavel que receberá coodenada X */
   var Y;  /* Variavel que receberá coodenada Y*/

   var objeto = document.getElementById(elemento);

   for( var X = 0, Y = 0; objeto.offsetParent; objeto = objeto.offsetParent ) {
     X += (objeto.offsetLeft)+5; /* Calcula a coordenada recebida + 5px */
     Y += (objeto.offsetTop)+2;  /*Idem, mas com 2px */
   }
    /* Deixa o objeto selecionado */
	 selectItem(elemento); 		
	 /* Se o botão pressionado for o direito, mostrao o menu na posição rastreada. */  	
	if(event.button==2){
		showmenu2(oid,X,Y);
	}
	return false;
}

/* função para mostrar dicas! */
function showtip(elemento,divtip) {
 
   var X;  /* Variavel que receberá coodenada X */
   var Y;  /* Variavel que receberá coodenada Y*/
   var objeto = document.getElementById(elemento); /*Elemento que enviara as coordenadas*/
   var tip = document.getElementById(divtip); /*Elemento que receberá as coordenadas*/
	   /*Caso a dica estiver visivel, esconda-a */
		if(tip.style.visibility=='visible') {
						tip.style.visibility='hidden';		
		}else {
   			for( var X = 0, Y = 0; objeto.offsetParent; objeto = objeto.offsetParent ) {
		   		  X += (objeto.offsetLeft)+1;
		     	  	  Y += (objeto.offsetTop)+1;
		   	}
   			/* Mostra a dica no local desejado! */
			   tip.style.top=Y+'px';
			   tip.style.left=X+'px';
			   tip.style.visibility='visible';
   	}
}

/* Abre nova janela */
function openwin(url,name,oid){

	var top;
	var left;

	/* Calculos para centralizar janela */ 
	top=(screen.height - 300) / 2;
	left=(screen.width - 400) / 2;

	/* Abre janela no centro da tela */
	win=window.open(url,name,'width=400,height=300,top='+top+',left='+left);

}

/*  Abrir local desejado */
function openlocation(url,oid){

 	selectItem(oid);
/*	document.getElementById(oid).style.backgroundColor='#eee';*/
	location=url
}

/* Confirma antes de abrir URL */
function asktodo(url,msg) {
	if(confirm(msg)){
		location=url;
	}
}

function ipt_show(idsh,idhd) {

	var objshow =  document.getElementById(idsh);
	var objhide =  document.getElementById(idhd);

	objshow.style.visibility='visible';
	objshow.focus();
	objhide.style.visibility='collapse';

}

function show_dialog(frm,ipt) {

	var dialog = document.getElementById(frm);
	var opacs = ["0",".1",".2",".3",".4",".5",".6",".7",".8",".9","1"];

	dialog.style.visibility='visible';
	dialog.style.opacity='0';
	for(var i=0;i<11;i++) {
		setTimeout('document.getElementById(\''+frm+'\').style.opacity="'+opacs[i]+'"', i * 40);
	}
	document.getElementById(ipt).focus();	

}

function save(met,url) {

/* met = metodo POST ou GET /*

/* Verifica se existe a função para aquele browser */
        xmlhttp = new XMLHttpRequest();

        var     Info = new Array();
	var 	mail;
	var	Member = new Array();

        Info[0]=document.getElementById('dn').value;
        Info[1]=document.getElementById('mailmember').value;
	
	mail=document.getElementById('members');
	
	size=mail.length;

	for(i=0;i<size;i++) {
		Member[i]=mail.options[i].value;
	}

	Member[size]=Info[1];

        url=url+"?dn="+Info[0];

	for(i=0;i<Member.length;i++) {
		url+="&&member[]="+Member[i];
	}
	
        xmlhttp.open(met,url,true);
        xmlhttp.onreadystatechange=function() {
	
           if(xmlhttp.readyState==4) {
	                alert(xmlhttp.responseText);
			document.location.reload();
                }
        }

        xmlhttp.send(null);
}

function del(met,url) {

/* met = metodo POST ou GET /*

/* Verifica se existe a função para aquele browser */
        xmlhttp = new XMLHttpRequest();

	var	Member = new Array();
	var 	mail;
	var	Info = new Array();

        Info[0]=document.getElementById('dn').value;

	mail=document.getElementById('members');
	
	size=mail.length;

	for(i=0;i<size;i++) {
		if(mail.options[i].selected){
			Member[i]=mail.options[i].value;
			/*alert(mail.options[i].value);*/
		}
	}

        url=url+"?dn="+Info[0];
       /* url+="&&member[]="+Info[1];*/
	for(i=0;i<Member.length;i++) {
		if(Member[i]) {
			alert(mail.options[i].value);
			url+="&&member[]="+Member[i];
		}
	}

	/*confirm(url);*/
        xmlhttp.open(met,url,true);
        xmlhttp.onreadystatechange=function() {

           if(xmlhttp.readyState==4) {
                        alert(xmlhttp.responseText);
			document.location.reload();
                }
        }
        xmlhttp.send(null);
}


function add_member(ipt,vlr) {

	var field = document.getElementById(ipt);
	var valor = document.getElementById(vlr).value;	

}
function hide(id){
	document.getElementById(id).style.visibility='hidden';
}

function close_window(msg) {
	if(confirm(msg)) {
		self.close();
	}
}
