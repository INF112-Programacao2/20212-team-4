<h1 align="center">
  <img alt="Banner" title="Banner" src="./assets/banner.png" />
  <br><br>
  :cowboy_hat_face:  :cowboy_hat_face:  :cowboy_hat_face: HIGHWAYMAN :cowboy_hat_face:  :cowboy_hat_face:  :cowboy_hat_face:
<br> </h1>

<h4 align="center">:test_tube: Status do Projeto: Fase de Testes :test_tube:</h4>
<h1></h1><br>

<h4 align="center">
 <a href="#motivacao">Motivação</a> •
 <a href="#premissa">Premissa</a> • 
 <a href="#tutorial">Tutorial para Execução</a> • 
 <a href="#devs">Desenvolvedores</a> • 
 <a href="#creditos">Créditos</a>
</h4><br>


<h2 id="motivacao">:cowboy_hat_face: Motivação:</h3>
<p align="justify"> Afim de cumprir com a proposta de um Projeto Final para a matéria de INF112, o nosso grupo decidiu criar um jogo na linguagem C++ (utilizada em nossas aulas) utilizando a biblioteca Allegro (já utilizada na matéria de Programação 1) de modo a aplicarmos alguns conceitos estudados nas aulas, como classes e objetos, herança e composição, entre outros, bem como boas práticas de programação.</p>
<br>


<h2 id="premissa">:cowboy_hat_face: Premissa:</h3>
<p> Highwayman é um jogo contextualizado no velho oeste com elementos de RPG no qual você deverá defender uma vila da invasão de uma gangue de pistoleiros. Converse com aldeões, encontre itens escondidos pelo mapa e desafie personagens para duelos nessa divertida aventura!</p>
<br>
<img alt="print" title="print" src="https://user-images.githubusercontent.com/92737180/159081590-aa0e4eb8-c1b9-4837-883b-0b887b6cc5b4.png">
<br>
<img alt="print" title="print" src="https://user-images.githubusercontent.com/92737180/159081702-1e993dc6-cf46-4c5b-9467-c737ab5aafb3.png">



<h2 id="tutorial">:cowboy_hat_face: Tutorial para Execução:</h3>
<h3 align="center"> :rotating_light: ATENÇÃO: esse tutorial é válido apenas para Windows. :rotating_light: </h3><br>
<p align=justify> Howdy, partner! Para jogar Highwayman, é necessário, além de baixar os arquivos compactados pelo GitHub, acrescentar o MinGW - um software que inclui cabeçalhos que serão interpretados pelo GCC 🤔, o compilador - que será adicionado as variáveis de ambiente do Windows.</p>
<br><br>
<b>:cowboy_hat_face: BAIXAR OS ARQUIVOS</b><br><br>
<p align=justify>Para baixar os arquivos em seu computador, vá em Code -> Download ZIP e salve o arquivo compactado onde desejar!<br>
<img alt="print" title="print" src="https://user-images.githubusercontent.com/92737180/160021595-c8fbbfa5-184a-4044-9b93-8c389125dd7b.png"></p>
<br>

<p align=justify>Depois, clique com o botão direito direto do mouse nele e selecione <b>"Extrair aqui"</b>.</p><br>
<img alt="print" title="print" src="https://user-images.githubusercontent.com/92737180/160021825-cf7d86e4-88d7-46d1-9519-8d1d283cdb1a.png">
<br><br>


<b>:cowboy_hat_face: ADIÇÃO DO MINGW NAS VARIÁVEIS DE AMBIENTE</b><br><br>
<p align=justify>Se esta parte lhe parece muito técnica, não se preocupe! Para isso, você não precisar ter o gatilho mais rápido do velho oeste! Acesse <b>https://drive.google.com/drive/folders/1bauTrrAK9UKedWnj19keHuFpxH_UX67X?usp=sharing</b> e faça o download do arquivo compactado que deixamos lá para você! (Não se preocupe se o Google lhe fornecer um aviso, caubói, o arquivo é grande demais para a carroça do GitHub e para o Google verificar se há virús, mas juramos que ele não faz mal).</p><br>
<img alt="print" title="print" src="https://user-images.githubusercontent.com/92737180/160021927-11eb6b32-ae3b-457a-8724-f59eaaf82422.png">
<br>

<p align=justify>Ao realizar o mesmo processo de extração que fizemos para o arquivo "20212-team-4-main", haverá uma pasta chamada "mingw64". Abra-a, vá para o diretório <b>bin</b> e copie o endereço desta pasta.</p><br>
<img alt="print" title="print" src="https://user-images.githubusercontent.com/92737180/160021988-c422d3d7-d955-44ea-b563-8c75846862e7.png">
<br>

<img alt="print" title="print" src="https://user-images.githubusercontent.com/92737180/160022032-f0533772-c64f-4d83-a47b-f6b9d6bcb120.png">
<br>

<p align=justify>Busque por <b>"Editar as Variáveis de Ambiente"</b>, clique em <b>"Variáveis de Ambiente..."</b> e dê dois cliques na repatição <b>"Path"</b> de <b>"Variáveis de usuário para Usuário"</b>.</p><br>
<img alt="print" title="print" src="https://user-images.githubusercontent.com/92737180/160022115-0d8859e5-8fdb-4b4b-964f-a09bdb5f076c.png">
<br>

<img alt="print" title="print" src="https://user-images.githubusercontent.com/92737180/160022243-0f4a350c-a498-46c7-9c36-1c547af38626.png">
<br>

<p align=justify>Clique em novo e cole no campo de texto o endereço copiado! Se quiser, selecione o endereço que você acabou de colar e clique em <b>"Mover para Cima"</b> até ficar no topo da lista. Por final, selecione <b>OK -> OK -> Aplicar -> OK </b>.</p><br>
<img alt="print" title="print" src="https://user-images.githubusercontent.com/92737180/160022311-488a8706-53b6-4a1c-addb-80c46643d464.png">
<br>

<p align=justify>Prontinho! O MinGW já está configurado e você já pode jogar! IHAAA! :cowboy_hat_face:</p><br>

<b>:cowboy_hat_face: E SE EU NÃO QUISER MAIS O MINGW?</b><br>
<p align=justify>É simples! Basta desfazer o processo! Vá novamente para Variáveis de <b>Ambiente -> Path</b>, selecione o endereço da página onde está o bin do MinGW e clique em Excluir e, depois, <b>OK -> OK -> Aplicar -> OK</b>. Agora, basta excluir a pasta que você criou para guardar os arquivos do jogo e do MinGW e está feito!</p>
<br><br>
<b>:cowboy_hat_face: EXECUTAR O JOGO</b><br><br>
<p align=justify>Para executar o jogo no seu computador, basta procurar pela pasta em que você descompactou os arquivos, clicar em "jogo" e, então, sua aventura começará!</p>
<br>

<h2 id="devs">:cowboy_hat_face: Desenvolvedores:</h3>
<a href="https://github.com/andrefeijosantos"><img alt="André Luiz" title="André Luiz" src="https://user-images.githubusercontent.com/92737180/155859397-1b3ea701-f098-45c8-822a-6ca773ec52c8.png"></a>
<a href="https://github.com/barbcristina"><img alt="Bárbara Cristina" title="Bárbara Cristina" src="https://user-images.githubusercontent.com/92737180/155859414-82c46baa-a4d4-4d7e-af15-d9314aa7bae3.png"></a>
<a href="https://github.com/laracolorida"><img alt="Lara Colorida" title="Lara Colorida" src="https://user-images.githubusercontent.com/92737180/155859416-edf4d200-608d-4564-a8d2-943c25eb775c.png"></a>
<a href="https://github.com/mvictoriaufv25"><img alt="Maria Victória" title="Maria Victória" src="https://user-images.githubusercontent.com/92737180/155859470-7748a1de-0fcc-47a2-9cb2-2673232c4c1f.png"></a>
<a href="https://github.com/Saulinhohh"><img alt="Saulo Henrique" title="Saulo Henrique" src="https://user-images.githubusercontent.com/92737180/155859419-4415a4f3-2113-463f-8bef-02612f37f1f4.png"></a>
<br>

<h2 id="creditos">:cowboy_hat_face: Créditos:</h3>
<ul>
  <li><a href="https://bakudas.itch.io/generic-oldwest-pack">Sprites das imagens</a></li>
  <li><a href="https://www.youtube.com/watch?v=hBMmoqdahpc">Highwayman - The Highwaymen (Instrumental)</a></li>
  <li><a href="https://www.youtube.com/watch?v=AFa1-kciCb4">Main Title (From “The Good, The Bad And The Ugly") - The City of Prague Philharmonic Orchestra</a></li>
  <li><a href="https://www.youtube.com/watch?v=-MK5ChLJTAk">American Venom - Rockstar</a></li>
  <li><a href="https://www.youtube.com/watch?v=lAGm9MTyRJ8">Eyes of the Wolf - CD Project Red</a></li>
  <li><a href="https://www.youtube.com/watch?v=fwsYlTbdKtM">Kyrie - Guilherme Arantes</a></li>
  <li><a href="https://www.youtube.com/watch?v=qBrSvLZ-NpU">Ghost Riders In The Sky - Stan Jones (Instrumental)</a></li>
</ul>
