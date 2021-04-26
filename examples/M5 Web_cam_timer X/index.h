/////////////////////////////////////////////
// HTML web page 
const char index_html0[] PROGMEM = R"rawliteral(  
        <div id="sidebar">
                    <input type="checkbox" id="nav-toggle-cb">
                    <nav id="menu">
                        <div class="input-group" id="framesize-group">
                            <label for="framesize">Resolution</label>
                            <select id="framesize" class="default-action">
                                <option value="11">QXGA(2048x1564)</option>
                                <option value="10">UXGA(1600x1200)</option>
                                <option value="9">SXGA(1280x1024)</option>
                                <option value="8">XGA(1024x768)</option>
                                <option value="7">SVGA(800x600)</option>
                                <option value="6">VGA(640x480)</option>
                                <option value="5">CIF(400x296)</option>
                                <option value="4" selected="selected">QVGA(320x240)</option>
                                <option value="3">HQVGA(240x176)</option>
                                <option value="0">QQVGA(160x120)</option>
                            </select>
                        </div>
                        <div class="input-group" id="quality-group">
                            <label for="quality">Quality</label>
                            <div class="range-min">4</div>
                            <input type="range" id="quality" min="4" max="63" value="10" class="default-action">
                            <div class="range-max">63</div>
                        </div>
                        <div class="input-group" id="brightness-group">
                            <label for="brightness">Brightness</label>
                            <div class="range-min">-3</div>
                            <input type="range" id="brightness" min="-3" max="3" value="0" class="default-action">
                            <div class="range-max">3</div>
                        </div>
                        <div class="input-group" id="contrast-group">
                            <label for="contrast">Contrast</label>
                            <div class="range-min">-3</div>
                            <input type="range" id="contrast" min="-3" max="3" value="0" class="default-action">
                            <div class="range-max">3</div>
                        </div>
                        <div class="input-group" id="saturation-group">
                            <label for="saturation">Saturation</label>
                            <div class="range-min">-4</div>
                            <input type="range" id="saturation" min="-4" max="4" value="0" class="default-action">
                            <div class="range-max">4</div>
                        </div>
                        <div class="input-group" id="sharpness-group">
                            <label for="sharpness">Sharpness</label>
                            <div class="range-min">-3</div>
                            <input type="range" id="sharpness" min="-3" max="3" value="0" class="default-action">
                            <div class="range-max">3</div>
                        </div>
                        <div class="input-group" id="denoise-group">
                            <label for="denoise">De-Noise</label>
                            <div class="range-min">Auto</div>
                            <input type="range" id="denoise" min="0" max="8" value="0" class="default-action">
                            <div class="range-max">8</div>
                        </div>
                        <div class="input-group" id="ae_level-group">
                            <label for="ae_level">Exposure Level</label>
                            <div class="range-min">-5</div>
                            <input type="range" id="ae_level" min="-5" max="5" value="0" class="default-action">
                            <div class="range-max">5</div>
                        </div>
                        <div class="input-group" id="gainceiling-group">
                            <label for="gainceiling">Gainceiling</label>
                            <div class="range-min">0</div>
                            <input type="range" id="gainceiling" min="0" max="511" value="0" class="default-action">
                            <div class="range-max">511</div>
                        </div>
                        <div class="input-group" id="special_effect-group">
                            <label for="special_effect">Special Effect</label>
                            <select id="special_effect" class="default-action">
                                <option value="0" selected="selected">No Effect</option>
                                <option value="1">Negative</option>
                                <option value="2">Grayscale</option>
                                <option value="3">Red Tint</option>
                                <option value="4">Green Tint</option>
                                <option value="5">Blue Tint</option>
                                <option value="6">Sepia</option>
                            </select>
                        </div>
                        <div class="input-group" id="awb-group">
                            <label for="awb">AWB Enable</label>
                            <div class="switch">
                                <input id="awb" type="checkbox" class="default-action" checked="checked">
                                <label class="slider" for="awb"></label>
                            </div>
                        </div>
                        <div class="input-group" id="dcw-group">
                            <label for="dcw">Advanced AWB</label>
                            <div class="switch">
                                <input id="dcw" type="checkbox" class="default-action" checked="checked">
                                <label class="slider" for="dcw"></label>
                            </div>
                        </div>
                        <div class="input-group" id="awb_gain-group">
                            <label for="awb_gain">Manual AWB</label>
                            <div class="switch">
                                <input id="awb_gain" type="checkbox" class="default-action" checked="checked">
                                <label class="slider" for="awb_gain"></label>
                            </div>
                        </div>
                        <div class="input-group" id="wb_mode-group">
                            <label for="wb_mode">AWB Mode</label>
                            <select id="wb_mode" class="default-action">
                                <option value="0" selected="selected">Auto</option>
                                <option value="1">Sunny</option>
                                <option value="2">Cloudy</option>
                                <option value="3">Office</option>
                                <option value="4">Home</option>
                            </select>
                        </div>
                        <div class="input-group" id="aec-group">
                            <label for="aec">AEC Enable</label>
                            <div class="switch">
                                <input id="aec" type="checkbox" class="default-action" checked="checked">
                                <label class="slider" for="aec"></label>
                            </div>
                        </div>
                        <div class="input-group" id="aec_value-group">
                            <label for="aec_value">Manual Exposure</label>
                            <div class="range-min">0</div>
                            <input type="range" id="aec_value" min="0" max="1536" value="320" class="default-action">
                            <div class="range-max">1536</div>
                        </div>
                        <div class="input-group" id="aec2-group">
                            <label for="aec2">Night Mode</label>
                            <div class="switch">
                                <input id="aec2" type="checkbox" class="default-action" checked="checked">
                                <label class="slider" for="aec2"></label>
                            </div>
                        </div>
                        <div class="input-group" id="agc-group">
                            <label for="agc">AGC</label>
                            <div class="switch">
                                <input id="agc" type="checkbox" class="default-action" checked="checked">
                                <label class="slider" for="agc"></label>
                            </div>
                        </div>
                        <div class="input-group hidden" id="agc_gain-group">
                            <label for="agc_gain">Gain</label>
                            <div class="range-min">1x</div>
                            <input type="range" id="agc_gain" min="0" max="64" value="5" class="default-action">
                            <div class="range-max">64x</div>
                        </div>
                        <div class="input-group" id="raw_gma-group">
                            <label for="raw_gma">GMA Enable</label>
                            <div class="switch">
                                <input id="raw_gma" type="checkbox" class="default-action" checked="checked">
                                <label class="slider" for="raw_gma"></label>
                            </div>
                        </div>
                        <div class="input-group" id="lenc-group">
                            <label for="lenc">Lens Correction</label>
                            <div class="switch">
                                <input id="lenc" type="checkbox" class="default-action" checked="checked">
                                <label class="slider" for="lenc"></label>
                            </div>
                        </div>
                        <div class="input-group" id="hmirror-group">
                            <label for="hmirror">H-Mirror</label>
                            <div class="switch">
                                <input id="hmirror" type="checkbox" class="default-action" checked="checked">
                                <label class="slider" for="hmirror"></label>
                            </div>
                        </div>
                        <div class="input-group" id="vflip-group">
                            <label for="vflip">V-Flip</label>
                            <div class="switch">
                                <input id="vflip" type="checkbox" class="default-action" checked="checked">
                                <label class="slider" for="vflip"></label>
                            </div>
                        </div>
                        <div class="input-group" id="bpc-group">
                            <label for="bpc">BPC</label>
                            <div class="switch">
                                <input id="bpc" type="checkbox" class="default-action">
                                <label class="slider" for="bpc"></label>
                            </div>
                        </div>
                        <div class="input-group" id="wpc-group">
                            <label for="wpc">WPC</label>
                            <div class="switch">
                                <input id="wpc" type="checkbox" class="default-action" checked="checked">
                                <label class="slider" for="wpc"></label>
                            </div>
                        </div>
                        <div class="input-group" id="colorbar-group">
                            <label for="colorbar">Color Bar</label>
                            <div class="switch">
                                <input id="colorbar" type="checkbox" class="default-action">
                                <label class="slider" for="colorbar"></label>
                            </div>
                        </div>
                        <div class="input-group" id="face_detect-group">
                            <label for="face_detect">Face Detection</label>
                            <div class="switch">
                                <input id="face_detect" type="checkbox" class="default-action">
                                <label class="slider" for="face_detect"></label>
                            </div>
                        </div>
                        <div class="input-group" id="face_recognize-group">
                            <label for="face_recognize">Face Recognition</label>
                            <div class="switch">
                                <input id="face_recognize" type="checkbox" class="default-action">
                                <label class="slider" for="face_recognize"></label>
                            </div>
                        </div>
                        <section id="buttons">
                            <button id="get-still">Get Still</button>
                            <button id="toggle-stream">Start Stream</button>
                            <button id="face_enroll" class="disabled" disabled="disabled">Enroll Face</button>
                        </section>
                    </nav>
                </div>
                
            </div>
        </section>
        
<script>

document.addEventListener('DOMContentLoaded', function (event) 
{ 
var cc= document.location.hostname;
var my_port = document.location.port;
if (my_port == "") my_port = "80";
var num = parseInt(my_port) + 1;
var port_n = num.toString();
var baseHost = document.location.origin;
var streamUrl = 'http://'+cc +':'+port_n; 
 
  const hide = el => {
    el.classList.add('hidden')
  }
  const show = el => {
    el.classList.remove('hidden')
  }

  const disable = el => {
    el.classList.add('disabled')
    el.disabled = true
  }

  const enable = el => {
    el.classList.remove('disabled')
    el.disabled = false
  }

  const updateValue = (el, value, updateRemote) => {
    updateRemote = updateRemote == null ? true : updateRemote
    let initialValue
    if (el.type === 'checkbox') {
      initialValue = el.checked
      value = !!value
      el.checked = value
    } else {
      initialValue = el.value
      el.value = value
    }

    if (updateRemote && initialValue !== value) 
    {
      updateConfig(el);
    } 
    else if(!updateRemote)
    {
      if(el.id === "aec"){
        value ? hide(exposure) : show(exposure)
      } else if(el.id === "agc"){
        if (value) {
          hide(agcGain)
        } else {
          show(agcGain)
        }
      } else if(el.id === "awb_gain"){
        value ? show(wb) : hide(wb)
      } else if(el.id === "face_recognize"){
        value ? enable(enrollButton) : disable(enrollButton)
      }
    }
  }

  function updateConfig (el) {
    let value
    switch (el.type) {
      case 'checkbox':
        value = el.checked ? 1 : 0
        break
      case 'range':
      case 'select-one':
        value = el.value
        break
      case 'button':
      case 'submit':
        value = '1'
        break
      default:
        return
    }

    const query = `${baseHost}/password/control?var=${el.id}&val=${value}`

    fetch(query)
      .then(response => {
        console.log(`request to ${query} finished, status: ${response.status}`)
      })
  }

  document
    .querySelectorAll('.close')
    .forEach(el => {
      el.onclick = () => {
        hide(el.parentNode)
      }
    })

  // read initial values
  fetch(`${baseHost}/password/status`)
    .then(function (response) {
      return response.json()
    })
    .then(function (state) {
      document
        .querySelectorAll('.default-action')
        .forEach(el => {
            updateValue(el, state[el.id], false)
        })
    })

  const view = document.getElementById('stream')
  const viewContainer = document.getElementById('stream-container')
  const stillButton = document.getElementById('get-still')
  const streamButton = document.getElementById('toggle-stream')
  const enrollButton = document.getElementById('face_enroll')
  const closeButton = document.getElementById('close-stream')

  const stopStream = () => {
    window.stop();
    hide(viewContainer)
  }



  
  const startStream = () => 
  {
    view.src = `${streamUrl}/password/srautas`
    show(viewContainer)
  }
  

   
  // Attach actions to buttons
  stillButton.onclick = () => {
    stopStream()
    view.src = `${baseHost}/password/capture?_cb=${Date.now()}`
    show(viewContainer)
  }

  closeButton.onclick = () => {
    stopStream()
    hide(viewContainer)
  }

  streamButton.onclick = () => {
    startStream()
  }

  enrollButton.onclick = () => {
    updateConfig(enrollButton)
  }

  // Attach default on change action
  document
    .querySelectorAll('.default-action')
    .forEach(el => {
      el.onchange = () => updateConfig(el)
    })

  // Custom actions
  // Gain
  const agc = document.getElementById('agc')
  const agcGain = document.getElementById('agc_gain-group')
  agc.onchange = () => {
    updateConfig(agc)
    if (agc.checked) {
      hide(agcGain)
    } else {
      show(agcGain)
    }
  }

  // Exposure
  const aec = document.getElementById('aec')
  const exposure = document.getElementById('aec_value-group')
  aec.onchange = () => {
    updateConfig(aec)
    aec.checked ? hide(exposure) : show(exposure)
  }

  // AWB
  const awb = document.getElementById('awb_gain')
  const wb = document.getElementById('wb_mode-group')
  awb.onchange = () => {
    updateConfig(awb)
    awb.checked ? show(wb) : hide(wb)
  }

  // Detection and framesize
  const detect = document.getElementById('face_detect')
  const recognize = document.getElementById('face_recognize')
  const framesize = document.getElementById('framesize')

  framesize.onchange = () => {
    updateConfig(framesize)
    if (framesize.value > 5) {
      updateValue(detect, false)
      updateValue(recognize, false)
    }
  }

  detect.onchange = () => {
    if (framesize.value > 5) {
      alert("Please select CIF or lower resolution before enabling this feature!");
      updateValue(detect, false)
      return;
    }
    updateConfig(detect)
    if (!detect.checked) {
      disable(enrollButton)
      updateValue(recognize, false)
    }
  }

  recognize.onchange = () => {
    if (framesize.value > 5) {
      alert("Please select CIF or lower resolution before enabling this feature!");
      updateValue(recognize, false)
      return;
    }
    updateConfig(recognize)
    if (recognize.checked) {
      enable(enrollButton)
      updateValue(detect, true)
    } else {
      disable(enrollButton)
    }
  }
})

function  run_delayed()
{
setTimeout(function(){ document.getElementById("toggle-stream").click(); }, 2000);
}
///////////
function update() 
{
var xhttp = new XMLHttpRequest();
var cc= document.location.hostname;
var my_port = document.location.port;
if (my_port == "") my_port = "80";
var demoUrl = 'http://'+ cc +':'+ my_port + '/password' + '/demo1'; 
  xhttp.onreadystatechange = function() 
  {
    if (this.readyState == 4 && this.status == 200) 
    {
      document.getElementById("demo1").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", demoUrl, true);
  xhttp.send();
}
///////////////
   
window.onload=function(){run_delayed();}; 

setInterval(update, 500);

</script>
</body>
</html>
)rawliteral";
